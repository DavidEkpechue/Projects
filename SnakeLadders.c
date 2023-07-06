#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GridLen 10
#define GridWid 10
#define MaxNumber 100
#define NumSnakes 6

// Color codes
#define RESET   "\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN    "\x1B[36m"
#define WHITE   "\x1B[37m"

typedef struct 
{
    int row;
    int col;
} 
Snake;

typedef struct 
{
    int row;
    int col;
    int playerid;
} Player;


int isSnakeHit(Snake snakes[], int numSnakes, int playerX, int playerY) 
{
    for (int i = 0; i < numSnakes; i++) 
    {
        if (playerX == snakes[i].col && playerY == snakes[i].row) 
        {
            return 1; // Snake hit
        }
    }
    return 0; // No snake hit
}


int main()
{
    int GridSize[GridLen][GridWid];
    int GameActive = 1;
    Player player1, player2;
    player1.col = 0;
    player1.row = 0;
    player2.col = 0;
    player2.row = 0;
    int PlayerCounter = 0;
    int CurrentGrid[1][1];
    int PlayerMove;
    int DiceRoll = 0;

    Snake snakes[NumSnakes] = 
    {
        {2, 2},
        {5, 3},
        {7, 0},
        {9, 4},
        {9, 9},
        {4,8}
    };

    while (GameActive == 1)
    {
        // Assign values to the grid
        for (int i = 0; i < GridLen; i++)
        {
            for (int j = 0; j < GridWid; j++)
            {
                GridSize[i][j] = i * GridWid + j + 1;
            }
        }

            // Set the snakes
        for (int i = 0; i < NumSnakes; i++)
        {
            int row = snakes[i].row;
            int col = snakes[i].col;
            GridSize[row][col] = -2;
        }



        // Print the grid with the player's position
        for (int i = 0; i < GridLen; i++)
        {
            for (int j = 0; j < GridWid; j++)
            {
                if (player1.col == i && player1.row == j && player2.col == i && player2.row == j)
                {
                    printf(MAGENTA " B  " RESET); // Print B in magenta to represent the shared point
                }
                else if (player1.col == i && player1.row == j)
                {
                    printf(GREEN " P1 " RESET); // Print P1 in green to represent player 1's position
                }
                else if (player2.col == i && player2.row == j)
                {
                    printf(BLUE " P2 " RESET); // Print P2 in blue to represent player 2's position
                }
                else
                {
                    switch (GridSize[i][j])
                    {
                        case -2:
                            printf(RED " S  " RESET); // Print S in red to represent snakes
                            break;

                        default:
                            printf("%3d ", GridSize[i][j]);
                            break;
                    }
                }
            }
            printf("\n");
        }

        
        // Check if the player hits a snake
        if (isSnakeHit(snakes, NumSnakes, player1.row, player1.col)) 
        {
            printf("\nYou hit a snake! Go back 5 spaces\n");

            if (player1.row > GridWid) 
            {
                player1.row = player1.row - (player1.row % GridWid);
            } 
            else 
            {
                player1.row -= 5;
            }
        }




                

        scanf("%d", &PlayerMove);

        switch (PlayerMove)
        {
        case 1:
            // Set the seed for the random number generator
            srand(time(NULL));

            // Generate a random number from 1 to 6
            DiceRoll = (rand() % 6) + 1;

            printf("You rolled: %d\n", DiceRoll);

            // Update the player's X coordinate based on the dice roll
            player1.row += DiceRoll;

            // Check if the player's X coordinate exceeds the grid width
            if (player1.row >= GridWid)
            {
                player1.row = player1.row % GridWid; // Wrap around to the next row
                player1.col++; // Move to the next row
            }

            if (DiceRoll == 6)
            {
                printf("You rolled a 6! Roll again!\n");
            }
            

            // Check if the player has reached the end of the grid
            if (player1.col >= GridLen)
            {
                printf("Congratulations! Player 1 reached %d.\n", MaxNumber);
                GameActive = 0; // End the game
            }
            break;
        case 2:
            // Set the seed for the random number generator
            srand(time(NULL));

            // Generate a random number from 1 to 6
            DiceRoll = (rand() % 6) + 1;

            printf("You rolled: %d\n", DiceRoll);

            // Update the player's X coordinate based on the dice roll
            player2.row += DiceRoll;

            // Check if the player's X coordinate exceeds the grid width
            if (player2.row >= GridWid)
            {
                player2.row = player1.row % GridWid; // Wrap around to the next row
                player2.col++; // Move to the next row
            }

            if (DiceRoll == 6)
            {
                printf("You rolled a 6! Roll again!\n");
            }
            

            // Check if the player has reached the end of the grid
            if (player2.col >= GridLen)
            {
                printf("Congratulations! Player 2 reached %d.\n", MaxNumber);
                GameActive = 0; // End the game
            }
            break;
            

        default:
            break;
        }
    }

    return 0;
}
