#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int newNumber;
    int numbersInArray;
    int* pArray;

    int* newArray = (int*)malloc((numbersInArray + 1) * sizeof(int));
    newArray = newNumber;
    for(int i = 1; i <= numbersInArray; i++)
    {
        newArray[i] = pArray[i - 1];
    }
    free(pArray);
    pArray = newArray;
}