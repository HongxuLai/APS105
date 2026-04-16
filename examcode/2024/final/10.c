#include <stdio.h>
#include <stdlib.h>

typedef struct database {
int* arr;
int length;
int size;
} Database;

void addElement(Database* x, int num)
{
    if(x -> length == x -> size)
    {
        int* newArr = (int*)malloc(sizeof(int) * x -> size *2);
        for(int i = 0; i < x -> length; i++)
        {
            newArr[i] = x -> arr[i];
        }
        free(x -> arr);
        x -> arr = newArr;
        x -> size *= 2;
    }
    x -> arr[x -> length] = num;
    x -> length ++;
    
}