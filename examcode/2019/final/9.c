#include <stdio.h>
#include <string.h>

void countLetters(char *s, int count[])
{
    for(int i = 0; s[i] != '\0'; i++)
    {
        if('a' <= s[i] && s[i] <= 'z')
        {
            count[s[i] - 'a'] ++;
        }
    }
    for(int i = 0; i < 26; i++)
    {
        if(count[i] != 0)
        {
            char c = 'a' + i;
            printf("%c: %d", c, count[i]);
        }
    }
}