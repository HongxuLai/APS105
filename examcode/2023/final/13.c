#include <stdio.h>
#include <string.h>

int numOccurrences(const char* str, const char* search)
{
    if(strstr(str, search) == NULL) return 0;
    else
    {
        return numOccurrences(strstr(str, search) + strlen(search), search);
    }
}