#include <stdio.h>
#include <string.h>

char* removeStrDuplicates(char* str, char* search)
{
    while(strstr(str, search) != NULL)
    {
        int ind = strstr(str, search) - str;
        int i = 0;
        while(str[ind + i + strlen(search)] != '\0')
        {
            str[ind + i] = str[ind + i + strlen(search)];
            i ++;
        }
        str[ind + i] = '\0';
    }
    return str;
}