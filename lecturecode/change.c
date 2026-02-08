#include <stdio.h>
int main(void)
{
    int d;
    int m;
    char slash;
    printf("Enter a date: ");
    scanf("%d%c%d", &d, &slash, &m);
    printf("%d%c%d", m, slash, d);
    return 0;
}