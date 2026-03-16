#include <stdio.h>

void countLetters(char* s, int count[]);

int main()
{
    return 0;
}

void countLetters(char* s, int count[])
{
    int i = 0;
    int whichLetter;
    while(s[i] != '\0')
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            whichLetter = s[i] - 'a';
            count[whichLetter] ++;
        }
        i ++;
    }
}