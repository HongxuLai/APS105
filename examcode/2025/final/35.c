#include <stdio.h>

int printNthElementinSpiralOrder(int rows, int cols, int arr[rows][cols], int n)
{
    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;
    int count = 0;

    while(top <= bottom && left <= right)
    {
        for(int i = left; i <= right; i++)
        {
            count ++;
            if(count == n) return arr[top][i];
        }
        top ++;

        for(int j = 0; j <= bottom; j++)
        {
            count ++;
            if(count == n) return arr[j][right];
        }
        right --;

        if(top <= bottom)
        {
            for(int i = right; i >= left; i--)
            {
                count ++;
                if(count == n) return arr[bottom][i];
            }
            bottom --;
        }

        if(left <= right)
        {
            for(int j = 0; j <= top; j--)
            {
                count ++;
                if(count == n) return arr[j][left];
            }
            left ++;
        }
    }
    return -1;
}