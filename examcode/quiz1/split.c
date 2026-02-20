#include <stdio.h>
#include <math.h>

int main(void)
{
    int num;
    char c;
    printf("Enter the input: ");
    scanf("%c%d", &c, &num);
    int number = num;
    int digit = 0;
    
    while(number > 0)
    {
        number /= 10;
        digit ++;
    }
    int firstpart;
    int lastpart;
    for(; digit > 0; digit--)
    {
        firstpart = num / (int)pow(10, digit - 1);
        lastpart = num % (int)pow(10, digit - 1);
        if(lastpart != 0)
        {
            printf("%d%c%d\n", firstpart, c, lastpart);
        }
        else
        {
            printf("%d%c\n", firstpart, c);
        }
    }
}