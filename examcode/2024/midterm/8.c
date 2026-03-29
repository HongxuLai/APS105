#include <stdio.h>

int sumDivisors(int num);
int main()
{
    printf("%d\n", sumDivisors(6));
    return 0;
}

int sumDivisors(int num)
{
    int sum = 0;
    for(int i = 1; i < num; i ++)
    {
        if(num % i == 0) sum += i;
    }
    return sum;
}