#include <stdio.h>
#include <string.h>

char *lastStringInString(char *s1, char *s2)
{
    char* p = s2;
    char* lastFound = NULL;
    while(*p != '\0')
    {
        if(strncmp(s1, p, strlen(s1)) == 0)
        {
            lastFound = p;
        }
        p++;
    }
    return lastFound;
}