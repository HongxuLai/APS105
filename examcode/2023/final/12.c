#include <stdio.h>
#include <string.h>

char* removeSpecialChars(char* str)
{
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] > 'z' || str[i] < 'a')
        {
            for(int j = i; j < strlen(str) - 1; i++)
            {
                str[j] = str[j + 1];
            }
            str[strlen(str) - 1] = '\0';
            i--;
        }
    }
    return str;
}