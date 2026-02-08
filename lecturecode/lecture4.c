#include <stdio.h>

int main(void)
{
    const double inchesToCM = 2.54;
    double inches;  
    /* 
    double %lf; int %d; float %f; char %c; 
    bool: (has no format specifier but if you use %d, it prints 0 for false and 1 for true)
    */ 
    printf("Enter the inches: ");
    scanf("%lf", &inches);
    double outCM = inches * inchesToCM;
    printf("Number of cm is %.2lf\n", outCM);
    return 0;
}