/*
    Write a C function named secondLargest that takes two arguments: an array
    of positive integers and the size of the array. The function should return the
    second largest element in the array. Assume that the array always has at least
    two elements. For example, given the array {3, 1, 4, 1, 5, 9, 2, 6, 5,
    3, 5} with length 11, the function should return 6. If all elements have the
    same value, the function should return 0.
    int secondLargest(int array[], int arrayLength) {
*/

#include <stdio.h>

int secondLargest(int array[], int arrayLength);

int main()
{
    int arr[11] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    printf("%d\n", secondLargest(arr, 11));
    return 0;
}

int secondLargest(int array[], int arrayLength)
{
    int largest = array[0];
    int secondLargest = 0;
    for(int i = 1; i < arrayLength; i++)
    {
        if(largest < array[i])
        {
            secondLargest = largest;
            largest = array[i];
        }
        else if (array[i] != largest && array[i] > secondLargest) secondLargest = array[i];
    }
    return secondLargest;
}