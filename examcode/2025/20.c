#include <stdio.h>
int main(void)
{
    int a = 0;
    int b = 0;
    int c = 0;
    printf("Enter three sides of a triangle: ");
    scanf("%d %d %d", &a, &b, &c);
    if(a + b <= c || a + c <= b || b + c <= a)
    {
        printf("Invalid Triangle\n");
    }
    else
    {
        if(a == b || a == c || b == c)
        {
            if(a == b && b == c)
            {
                printf("Equilateral Triangle\n");
            }
            else
            {
                printf("Isosceles Triangle\n");
            }
        }
        else
        {
            printf("Scalene Triangle\n");
        }
    }
}