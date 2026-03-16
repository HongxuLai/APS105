#include <stdio.h>

void reverseArray(int arr[], int size);

int main(void)
{
    return 0;
}

void reverseArray(int arr[], int size)
{
    int low = 0; 
    int high = size - 1;
    while(low <= high)
    {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low ++;
    }
}