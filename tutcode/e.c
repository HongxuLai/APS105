#include <stdio.h>
int main()
{
    double sum = 1.0;
    double delta = 1;
    for (int i = 1;; i ++)
    {
        double product = 1.0;
        for (int m = i; m > 0; m--)
        {
            product *= m;
        }
        delta = 1.0 / product;
        if (delta < 0.001) break;
        sum += delta;
    }
    printf("The value of e is approximately %f.\n", sum);
    return 0;
}