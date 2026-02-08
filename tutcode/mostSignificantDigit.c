#include <stdio.h>
int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    int mSiDigit = 0;
    while(num > 0)
    {
        int digit = num % 10;
        if (digit > mSiDigit) mSiDigit = digit;
        num = num / 10;
    }
    printf("%d\n", mSiDigit);
}