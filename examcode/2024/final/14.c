#include <stdio.h>
#include <string.h>

void mergeLines(char* merged, char* lineOne, char* lineTwo)
{
    if(lineOne[0] = '\0')
    {
        strcpy(merged, lineTwo);
    }
    if(lineTwo[0] = '\0') strcpy(merged, lineOne);

    if(lineOne[0] <= lineTwo[0])
    {
        merged[0] = lineOne[0];
        mergeLines(merged + 1, lineOne + 1, lineTwo);
    }
    else
    {
        merged[0] = lineTwo[0];
        mergeLines(merged + 1, lineOne, lineTwo + 1);
    }
}