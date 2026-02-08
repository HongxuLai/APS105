#include <stdio.h>
int main(void)
{
    double ft;
    double ct;
    printf("Enter the thermostat temperature: ");
    scanf("%lf", &ft);
    ct = (ft - 32) * 5 / 9;
    printf("\nThe temperature in Celsius is: %.1lf\n", ct);
    return 0;
}