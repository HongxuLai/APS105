#include <stdio.h>
#include <math.h>
int main()
{
    double d, H;
    const double g = 9.81;
    const int l = 2;
    const double v = 20;
    const double pi = acos(-1.0);
    printf("Please enter the horizontal distance from the wall between 3 and 30 m:\n");
    scanf("%lf", &d);
    while(d < 3 || d > 30)
    {
        printf("Please enter the horizontal distance from the wall between 3 and 30 m:\n");
        scanf("%lf", &d);
    } 
    printf("Please enter the target height between 3 and 6 m:\n");
    scanf("%lf", &H);
    while(H < 3 || H > 6)
    {
        printf("Please enter the target height between 3 and 6 m:\n");
        scanf("%lf", &H);
    }
    for(double alpha_degree = 0; alpha_degree <= 90; alpha_degree ++)
    {
        double alpha_rad;
        alpha_rad = alpha_degree / 180 * pi;
        double vx = v * cos(alpha_rad);
        double vy = v * sin(alpha_rad);
        double t = d / vx;
        double y = l + vy * t - 0.5 * g * t * t;
        if (fabs(y - H) <= 0.3){
            printf("The angle should be %.2lf\n", alpha_degree);
            break;
        }
    }
}