#include <stdio.h>
int main(void)
{
    double rate;
    int d;
    int fd = 0;
    int cd;
    double charge;
    printf("Enter the daily rate: ");
    scanf("%lf", &rate);
    printf("Enter the rental period (in days): ");
    scanf("%d", &d);
    fd = d / 4;
    cd = d - fd;
    charge = (cd * rate) * 1.13; 
    printf("Your total free day(s) in this rental is: %d\n", fd);
    printf("Your total charge including taxes is: %.2lf\n", charge);
}