/*
For a continuous mathematical function, if you know that its value is above
zero (positive) for one input value, and below zero (negative) for a second
input value, then it necessarily must cross zero. Below we implement such a
function in C, and we can verify that it works by calling myfn(1.0) , which
results positive and myfn(0.0), which results negative.
Your task is to complete the C program below to find the input that generates
a close to zero output. Your program will average the high input (highv)
and the low input (lowv), and replace highv or lowv with their average if the
output is positive (replace highv) or negative (replace lowv). At the end, the
program will print out the number of iterations taken to reach a difference
between highv and lowv to be at or below a certain value called Tolerance,
and the average of current values of highv and lowv.
For example, say the average of highv and lowv is named halfway. When
halfway is passed to the function, if the output of function myfn is negative,
then halfway is assigned to lowv, else it is assigned to highv. This repeats
until the absolute value of the difference between highv and lowv is at or
below Tolerance, as defined below.
For example, in the first iteration, at the start highv = 1.0 and lowv = 0.0.
The average is 0.5. The output of the function call myfn(0.5) is negative, so
lowv will be set to 0.5 for the next iteration.
*/


#include <stdio.h>
#include <math.h>

double myfn(double input) 
{
    return sin(input - 3.141 / 4.0);
}
int main(void) {
    double highv = 1.0,lowv = 0.0;
    int iterations = 0;
    const double Tolerance = .01;

    double halfway;
    double diff = fabs(highv - lowv);
    halfway = (highv + lowv) / 2.0;

    while(diff > Tolerance)
    {
        iterations ++;
        diff = fabs(highv - lowv);
        if(myfn(halfway) > 0)
        {
            highv = halfway;
        }
        else if(myfn(halfway) < 0)
        {
            lowv = halfway;
        }
        halfway = (highv + lowv) / 2.0;
    }

    printf("%d iterations\n",iterations);
    printf("value is %lf",halfway);
    return 0;
}
