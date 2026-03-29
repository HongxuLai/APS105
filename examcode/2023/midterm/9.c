#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numbersInArray = 100;
    int pArray[numbersInArray] = {0};
    int newNumber;
    int *newArray = (int *)malloc(sizeof(int) * (numbersInArray + 1));
    for (int i = 0; i < numbersInArray; i++)
    {
        newArray[i] = pArray[i];
    }
    newArray[numbersInArray] = newNumber;
    free(pArray);
    pArray = newArray;
}