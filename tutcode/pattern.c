#include <stdio.h>
int main()
{
    int m;
    printf("Enter the number of rows: ");
    scanf("%d", &m);
    for(int r = 1; r <= m; r++)
    {
        for(int c = 1; c <= m; c++)
        {
            if(r == 1 || r == m)
            {
                printf("*");
            }
            else
            {
                if (c == 1 || c == m ||  c == m + 1 - r)
                {
                    printf("*");
                }
                else printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}