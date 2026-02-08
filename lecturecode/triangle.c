#include <stdio.h>
int main()
{
    int n;
    printf("What's the size of triangle?\n");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int s = 0; s < n - i; s++)
        {
            printf(" ");
        }
        for (int star = 0; star < 2 * i -1; star++)
        {
            printf("*");
        }
        printf("\n");
    }
}