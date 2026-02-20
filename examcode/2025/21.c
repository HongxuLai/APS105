#include <stdio.h>

int sumEvenDigits(int num);

int main(void)
{
    printf("%d\n", sumEvenDigits(73456));
    return 0;
}

int sumEvenDigits(int num)
{
    int digit = 0;
    int evendigit = 0;
    int sum = 0;
    if (num < 0)
    {
        num = -num;
    }
    while(num > 0)
    {
        digit = num % 10;
        if(digit % 2 == 0)
        {
            evendigit = digit;
            sum += evendigit;
        }
        num /= 10;
    }
    return sum;
}