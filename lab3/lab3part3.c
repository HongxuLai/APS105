#include <stdio.h>
int main()
{
    int amount;
    printf("Please enter an amount in dollars ($): ");
    scanf("%d", &amount);
    while (amount % 5 != 0)
    {
        printf("The amount should be a multiple of $5: ");
        scanf("%d", &amount);
    }
    int divisors[] = {100, 50, 20, 10, 5};
    for (int i = 0; i < 5; i ++)
    {
        if (amount >= divisors[i])
        {
            int nums = amount / divisors[i];
            printf("$%d: %d\n", divisors[i], nums);
            amount = amount % divisors[i];
        }
    }
    return 0;
}