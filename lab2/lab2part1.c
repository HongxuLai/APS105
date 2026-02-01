#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c;
    double alpha, beta, gamma;
    const double pi = 3.14159265;
    printf("Enter the length of side A: ");
    scanf("%lf", &a);
    printf("Enter the length of side B: ");
    scanf("%lf", &b);
    printf("Enter the measure of angle alpha in degrees: ");
    scanf("%lf", &alpha);   
    beta = asin(b * sin(alpha / 180 * pi) / a) / pi * 180;
    gamma = 180 - beta - alpha;
    c = a * sin(gamma / 180 * pi) / sin(alpha / 180 * pi);
    printf("\nResults:\n");
    printf("Side A: %.2lf\n", a);
    printf("Side B: %.2lf\n", b);
    printf("Side C: %.2lf\n", c);
    printf("Angle Alpha: %.2lf degrees\n", alpha);
    printf("Angle Beta: %.2lf degrees\n", beta);
    printf("Angle Gamma: %.2lf degrees\n", gamma);
}