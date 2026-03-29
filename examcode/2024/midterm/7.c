#include <stdio.h>

int main()
{
    int d1, d2, m1, m2;
    char c;
    printf("Enter first date (day / month): ");
    scanf("%d%c%d", &d1, &c, &m1);
    printf("Enter second date (day / month): ");
    scanf("%d%c%d", &d2, &c, &m2);

    if(m1 > m2) printf("First date is later\n");
    else if(m1 == m2)
    {
        if(d1 > d2) printf("First date is later\n");
        else if(d1 < d2) printf("Second date is later\n");
        else printf("It's the same date\n");
    }
    else printf("Second date is later\n");
}