#include <stdio.h>

int borderSum(int mat[][26], int n)
{
    int sum = 0;
    if(n == 0) return 0;
    for(int r = 0; r < n; r++)
    {
        for(int c = 0; c < n; c++)
        {
            if(r == 0 || r == n - 1 || c == 0 || c == n - 1)
            {
                sum += mat[r][c];
            }
        }
    }
    return sum;
}