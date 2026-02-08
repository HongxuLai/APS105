#include <stdio.h>
#include <math.h>
int main()
{
    double rate;
    double usd;
    double cad;
    printf("Enter the exchange rate (1 CAD = ? USD): ");
    scanf("%lf", &rate);
    printf("Enter the value in US dollars: ");
    scanf("%lf", &usd);
    cad = rint(usd *100 / 0.75) / 100;
    printf("The value in Candaian dollars is %lf\n", cad);
}