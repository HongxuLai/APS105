#include <stdio.h>
#include <string.h>


char* removeSpecialChars(char* str);
int main(void) 
{
    char str[30] = "a&pp*(leisa(fr*$uit";
    printf("str with special characters: %s\n", removeSpecialChars(str));
    return 0;
}

char* removeSpecialChars(char* str)
{
    int ind = 0;
    for(;ind < strlen(str); ind++)
    {
        if(str[ind] > 'z' || str[ind] < 'a')
        {
            for(int i = ind; i < strlen(str); i++)
            {
                str[i] = str[i + 1];
            }
            str[strlen(str) - 1] = '\0';
            ind --;
        }
    }
    return str;
}