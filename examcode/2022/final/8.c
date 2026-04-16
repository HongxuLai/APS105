#include <stdio.h>

int main()
{
    int sum = 0;
    for(int i = 1; i <= 999; i++)
    {
        if(i % 9 == 0 && i % 2 == 0)
        {
            int tenDigit = 0;
            tenDigit = i / 10 - (i / 100) * 10;
            if(tenDigit != 7) sum += i;
        }
    }
    printf("%d", sum);
    return 0;
}