#include <stdio.h>
#include <stdbool.h>

int mysqrt(int x);
bool isPrime(int x);
int nextPrime(int *px);

int main()
{
    int num;
    printf("Enter your number ");
    scanf("%d", &num);

    int x = 2;
    bool verified = false;
    bool rejected = false;
    int *px = &x;
    *px = x;
    while (!verified && !rejected)
    {
        int y = num - x;
        if (isPrime(y))
        {
            printf("%d = %d + %d ", num, x, y);
            verified = true;
        }
        else if (x > y) rejected = true;
        else x = nextPrime(px);
    }
}

int mysqrt(int x)
{
    int left = 0;
    int right = x;
    int mid;
    int ans;
    while(left <= right)
    {
        mid = (left + right) / 2;
        if (mid * mid <= x)
        {
            ans = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    return ans;
}

bool isPrime(int x)
{
    bool prime = true;
    if (x < 2) prime = false;
    if (x == 2) return true; 
    for (int i = 2; i <= mysqrt(x); i++)
    {
        if (x % i == 0) 
        {
            prime = false;
            break;
        }
    }
    return prime;
}

int nextPrime(int *px)
{
    int value = *px + 1;
    while(!isPrime(value))
    {
        value ++;
    }
    *px = value;
    return *px;
}