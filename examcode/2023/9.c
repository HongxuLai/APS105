#include <stdio.h>

int main()
{
    return 0;
}

int barcodeDigit(int n)
{
    int arr[11];
    int sum = n;
    for(int i = 11; i >= 1; i--)
    {
        arr[i] = n % 10;
        sum = n / 10;
    }

    int sum1 = 0;
    for(int i = 1; i <= 11; i++)
    {
        if(i % 2 == 1)
        {
            sum1 += arr[i];
        }
    }
    sum1 *= 3;
    for(int i = 1; i <= 11; i++)
    {
        if(i % 2 == 0)
        {
            sum1 += arr[i];
        }
    }

    int M = sum1 % 10;
    if(M == 0) return 0;
    else return 10 - M;
}