#include <stdio.h>
#include <stdbool.h>

bool hasSameNumbers(int *a, int *b)
{
    int countA = 0;
    int countB = 0;
    for(int i = 0; a[i] != -1; i ++)
    {
        countA ++;
    }
    for(int i = 0; b[i] != -1; i ++)
    {
        countB ++;
    }

    if(countA != countB) return false;
    else
    {
        bool same = true;
        for(int i = 0; a[i] != -1; i++)
        {
            same  = false;
            for(int j = 0; b[j] != -1; j++)
            {
                if(a[i] == b[j]) same = true;
            }
        }
    }
    return same;
}