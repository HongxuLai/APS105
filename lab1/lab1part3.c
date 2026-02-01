#include <stdio.h>
int main(void)
{
    double a;
    printf("Please provide a distance in metres: ");
    scanf("%lf", &a);
    int y = a / 0.9144;
    int f = (a - y * 0.9144) / 0.3048;
    int i = (a - y * 0.9144 -f * 0.3048) / 0.0254;
    double rem = (a - y * 0.9144 -f * 0.3048 - i * 0.0254) / 0.0254;
    printf("%d yards, %d feet, %d inches, %.2lf inches remainder\n", y, f, i, rem);
}