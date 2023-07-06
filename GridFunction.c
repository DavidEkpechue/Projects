#include <stdio.h>
#include <math.h>

#define GridLen 10
#define GridWid 10

int main ()
{
    //2D array holds grid info
    int GridSize[GridLen][GridWid];

    //Assign values to the grid
    for (int i = 0; i < GridLen; i++)
    {   
        for (int j = 0; j < GridWid; j++)
        {   
            /*  
                i * GridWid represents the row index (i) multiplied by the grid width (GridWid)
                j represents the column index, which specifies the offset from the starting value of the row.
                j + 1 is added to the row starting value to shift the numbers by 1. Since array indices start from 0 in C 
                Adding 1 ensures that the first number in the grid is 1 instead of 0.
            */

            GridSize[i][j] = i * GridWid + j + 1;
        }
    }
    
    for (int i = 0; i < GridLen; i++)
    {
        for (int j = 0; j < GridWid; j++)
        {
            printf("%3d ", GridSize[i][j]);
        }
        printf("\n");
    }

    return 0;
}
