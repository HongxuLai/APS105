#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isAnagram(char* s1, char* s2)
{
    if(strlen(s1) != strlen(s2)) return false;

    bool found = false;
    
    for(int i1 = 0; s1[i1] != '\0' && !found; i1 ++)
    {
        int i2 = 0;
        for(; s2[i2] != '\0'; i2 ++)
        {
            if (s1[i1] == s2[i2]) found = true;
        }

        if(found)
        {
            s2[i2] = '?';
        }
        else found = false;
    }

    return found;
}