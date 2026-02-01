#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* two prototype functions */
double randDouble();
bool inSafeZone(double x, double y);
double round4(double x);

int main()
{
    srand(67); // set 67 seed before first rand()
    int iterations;
    double p;
    double safetimes = 0.0;

    /* scanf iteration times */
    printf("Number of Monte Carlo iterations: ");
    scanf("%d", &iterations);

    for (int i = 0; i < iterations; i ++)
    {
        // generate random numbers
        double x = 2.0 * randDouble() - 1.0;
        double y = 2.0 * randDouble() - 1.0;

        if (inSafeZone(x, y))
        {
            safetimes += 1;
        }
    }

    p = round4(safetimes / iterations); // round p to 4 demical places
    printf("Probability of safe landing: %.4f\n", p);
}


double randDouble()
{
    return (double)rand() / ((double)RAND_MAX + 1); 
}

bool inSafeZone(double x, double y)
{
    double sum = x * x + y * y; // judge if in safe zone
    if (sum <= 1)
    {
        return true;
    }
    else return false;
}

double round4(double x)
{
    return (int)(x * 10000 + 0.5) / 10000.0;
    // round without math.h
}
