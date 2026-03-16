#include <stdio.h>

void printPairs(int arr[], int size, int target)
{
    for(int i = 0; i < size; i ++)
    {
        for(int j = i + 1; j < size; j ++)
        {
            int sum = arr[i] + arr[j];
            if (sum == target)
            {
                printf("(%d, %d)\n", arr[i], arr[j]);
            }
            while(i + 1 < size && arr[i] == arr[i + 1])
            {
                i += 1;
            }
            while(j + 1 < size && arr[j + 1] == arr[j])
            {
                j += 1;
            }
        }
    }
}