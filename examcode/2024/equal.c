#include <stdio.h>
#include <stdbool.h>

bool isMagicSquare(int n, int square[][n]);

int main()
{
    return 0;
}

bool isMagicSquare(int n, int square[][n])
{
    int Sum = 0;
    int SumDiag = 0;
    for (int i = 0; i < n; i ++)
    {
        Sum += square[i][i];
        SumDiag += square[i][n - 1 -i];
    }
    if(Sum != SumDiag) return false;

    int sumRow = 0;
    int sumCol = 0;
    for(int r = 0; r < n; r ++)
    {
        for(int c = 0; c < n; c ++)
        {
            sumRow += square[r][c];
            sumCol += square[c][r];
        }
        if (sumRow != Sum || sumCol != Sum)
        {
            return false;
        }
    }

    return true;
}