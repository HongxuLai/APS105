#include <stdio.h>
#include <string.h>

void recurPrint(char* str);

int main(void) {
    char s[] = "APS105";
    recurPrint(s);
    return 0;
}

void recurPrint(char* str)
{
    if(*str != '\0')
    {
        printf("%s", str);
        int len = strlen(str);
        char store = str[len - 1];
        str[len - 1] = '\0';
        recurPrint(str);
        str[len - 1] = store;
        printf("%s", str);
    }
}