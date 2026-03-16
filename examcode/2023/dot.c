#include <stdio.h>


int dotProduct(int arrA[], int arrB[]);
int main(void) 
{
    int arr1[] = {2, 3, 4, 5, 9, -1};
    int arr2[] = {7, 8, 9, 9, 3, -1};
    printf("Dot product is %d.\n", dotProduct(arr1, arr2));
    return 0;
}

int dotProduct(int arrA[], int arrB[])
{
    int countA = 0;
    int countB = 0;

    for(int i = 0; arrA[i] != -1; i++) countA ++;
    for(int i = 0; arrB[i] != -1; i++) countB ++;
    
    int sum = 0;

    if(countA != countB) sum = -1;
    else
    {
        for(int i = 0; arrA[i] != -1 && arrB != -1; i ++)
        {
            sum += arrA[i] * arrB[i];
        }
    }

    return sum;
}