#include <stdio.h>
#include <math.h>


double myfn(double input) 
{
    return sin(input - 3.141 / 4.0);
}
int main(void) 
{
    double highv = 1.0,lowv = 0.0;
    int iterations = 0;
    const double Tolerance = .01;
    double diff = 0.0;
    double halfway = 0.0;

    halfway = (highv + lowv) / 2;
    diff = fabs(highv - lowv);

    while(diff > Tolerance)
    {
        iterations ++;
        diff = fabs(highv-lowv);
        if(myfn(halfway) >= 0.0)
        {
            highv = halfway;
        }
        else lowv = halfway;
        halfway = (highv + lowv) / 2;
    }
    printf("%d iterations\n",iterations);
    printf("value is %lf",halfway);
    return 0;
} 