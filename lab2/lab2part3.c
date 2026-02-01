#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    const double k = 8.9875e9;
    char unit1[3], unit2[3];
    double q1, q2;
    double r;
    printf("Enter the value of the two charges separated by a space: ");
    scanf("%lf%2s %lf%2s", &q1, unit1, &q2, unit2);
    printf("Enter distance between charges in metres: ");
    scanf("%lf", &r);
    if (strcmp(unit1, "nC") == 0)
    {
        q1 *= 1e-9;
    }
    else if(strcmp(unit1, "uC") == 0)
    {
        q1 *= 1e-6;
    }
    if (strcmp(unit2, "nC") == 0)
    {
        q2 *= 1e-9;
    }
    else if(strcmp(unit2, "uC") == 0)
    {
        q2 *= 1e-6;
    }
    double F;
    F = k * fabs(q1 * q2) / (r * r);
    if (F < 1e-6) 
    {
        printf("The force between charges is %.2fnN (less than 1uN)\n", F * 1e9);
    }
    else if (F < 1e-3) 
    {
        printf("The force between charges is %.2fuN (less than 1mN)\n", F * 1e6);
    }
    else if (F < 1) 
    {
        printf("The force between charges is %.2fmN (less than 1N)\n", F * 1e3);
    }
    else 
    {
        printf("The force between charges is %.2fN (1N or greater)\n", F);
    }
    return 0;
}