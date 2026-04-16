#include <stdio.h>

int findLargestWaterBody(int rows, int cols, int arr[rows][cols])
{
    int largest = 0;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(arr[i][j] == 0)
            {
                int count = countWater(rows, cols, arr[rows][cols], i, j);
                if(count > largest) largest = count;
            }
        }
    }
}

int countWater(int rows, int cols, int arr[rows][cols], int r, int c)
{
    if(r < 0 || r >= rows || c < 0 || c >= cols || arr[r][c] != 0) return 0;
    arr[r][c] = 1;
    int count = 1;
    for(int deltaR = -1; deltaR <= 1; deltaR ++)
    {
        for(int deltaC = -1; deltaC <= 1; deltaC ++)
        {
            count += countWater(rows, cols, arr[rows][cols], r + deltaR, c + deltaC);
        }
    }
    return count;
}