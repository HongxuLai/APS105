#include <stdio.h>

void printPairs(int arr[], int size, int target);

int main(void)
{
    return 0;
}

void printPairs(int arr[], int size, int target)
{
    int expectednum = 0;
    for(int i = 0; i < size; i ++)
    {
        if (i > 0 && arr[i] == arr[i - 1]) continue;

        expectednum = target - arr[i];
        for(int m = i + 1; m < size; m ++)
        {
            if (m > i + 1 && arr[m] == arr[m - 1]) continue;

            if (arr[m] == expectednum)
            {
                printf("(%d, %d)\n", arr[i], arr[m]);
                break;
            }
            else break;
        }
    }
}