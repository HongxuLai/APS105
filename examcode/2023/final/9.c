#include <stdio.h>

int diagonalsSum(int n, int square[][n])
{
    int sumDia = 0, sumReDia = 0;
    for(int i = 0; i < n; i ++)
    {
        sumDia += square[i][i];
        sumReDia += square[i][n - 1 - i];
    }
    int sum = sumDia + sumReDia;
    return sum;
}