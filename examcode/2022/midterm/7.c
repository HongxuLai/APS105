#include <stdio.h>
#include <math.h>

int main()
{
    int num = 0;
    printf("Please enter the digits to be rotated: ");
    scanf("%d", &num);
    int times;
    printf("By how much? ");
    scanf("%d", &times);

    int digit = 0;
    int num1 = num;
    while(num1 > 0)
    {
        digit ++;
        num1 /= 10;
    }

    int num2 = num;
    if(times < digit)
    {
        int leftpart = num2 / pow(10, digit - times);
        int rightpart = num2 - leftpart * pow(10, digit - times);
        num = leftpart + pow(10, times) * rightpart;
    }

    printf("You rotated your digits anticlockwise %d times to be %d\n", times, num);
    return 0;
}