#include <stdio.h>

void printReverse()
{
    int num = 0;
    printf("Enter num: ");
    scanf("%d", &num);
    if(num > 0)
    {
        printReverse();
        printf("%d", num);
    }
    else printf("Reversed sequence: 0 ");
}