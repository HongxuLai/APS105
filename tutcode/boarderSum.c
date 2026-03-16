#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    return 0;
}

int boarderSum(int mat[][26], int n)
{
    int sum = 0;
    int **arr = (int **)malloc(n * sizeof(int*));
    for(int r = 0; r < n; r ++)
    {
        *(arr + r) = (int *)malloc(n * sizeof(int));
        for (int c = 0; c < n; c ++)
        {
            *(*(arr + r) + c) = mat[r][c];
        }
    }
    for(int r = 0; r < n; r++)
    {
        for(int c = 0; c < n; c++)
        {
            if(r == 0 || r == n - 1 || c == 0 || c == n - 1) sum += mat[r][c];
        }
    }
    return sum;
}