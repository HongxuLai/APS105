#include <stdio.h>
int sortTemp(int temp[], int size);

int main(void) 
{
    int temp[7] = {5, 4, 10, 11, 11, 10, 4};
    printf("\nThe lowest temperature is %d\n", sortTemp(temp, 7));
    return 0;
}

int sortTemp(int temp[], int size)
{
    int histo[12] = {0};
    for(int i = 0; i < size; i++)
    {
        histo[temp[i]] ++;
    }
    for(int i = 0; i < 12; i++)
    {
        printf("%d", histo[i]);
    }
    printf("\n");

    int ind = 0;
    for(int i = 0; i < 12; i++)
    {
        while(histo[i] != 0)
        {
            temp[ind] = i;
            histo[i] --;
            temp++;
        }
        
    }
}