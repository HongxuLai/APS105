#include <stdio.h>
#include <stdbool.h>

bool isMagicSquare(int n, int square[][n])
{
    int sumDia = 0;
    int sumReDia = 0;

    for(int i = 0; i < n; i ++)
    {
        sumDia += square[i][i];
        sumReDia += square[i][n - 1 -i];
    }
    if(sumDia != sumReDia) return false;

    for(int i = 0; i < n; i++)
    {
        int sumRow = 0;
        int sumCol = 0; 
        for(int j = 0; j < n; j++)
        {
            sumRow += square[i][j];
            sumCol += square[j][i];
        }
        if(sumCol != sumDia || sumRow != sumDia) return false;
    }
    return true;
}