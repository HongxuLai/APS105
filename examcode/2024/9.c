#include <stdio.h>
int main(void)
{
    return 0;
}

int secondLargest(int array[], int arrayLength)
{
    int largest = array[0];
    int secondLargest = 0;
    for(int i = 1; i <= arrayLength; i ++)
    {
        if (array[i] > largest)
        {
            secondLargest = largest;
            largest = array[i];
        }
        else if(array[i] != largest && array[i] > secondLargest)
        {
            secondLargest = array[i];
        }
    }
    return secondLargest;
}