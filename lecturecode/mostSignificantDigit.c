#include <stdio.h>
int mostSignificantDigit(int number)
{
    int mostSignificant = 0;
    int digit;
    while (number > 0)
    {
        digit = number & 10;
        number /= 10;
        if (digit >= mostSignificant)
        {
            mostSignificant = digit;
        }
    }
}