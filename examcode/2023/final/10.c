#include <stdio.h>

int sortArray(int inArray[],int outArray[], int sizeOfInArray)
{
    int countArray[600];
    for(int i = 0; i < 600; i++)
    {
        countArray[i] = 0;
    }
    for(int i = 0; i < sizeOfInArray; i++)
    {
        countArray[inArray[i]] ++;
    }

    int index = 0;
    for(int i = 0; i < 600; i++)
    {
        while(countArray[i] > 0)
        {
            outArray[index] = i;
            countArray[i] --;
            index ++;
        }
    }
    return index;
}