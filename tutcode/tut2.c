#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    int r;
    r = rand() % 301 - 150;
    if (r % 2 == 0)
    {
        printf("%d is even. You win!\n", r);
    }
    else
    {
        printf("You lose!\n");
    }
}