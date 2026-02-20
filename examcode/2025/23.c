#include <stdio.h>

double average(int grades[], int gradesLength);
double variance(int grades[], int gradesLength);

int main(void) {
  int grades[] = {70, 72, 75, 85};
  int gradesLength = 4;
  printf("Average: %.1lf\n", average(grades, gradesLength));
  printf("Variance: %.1lf\n", variance(grades, gradesLength));
  return 0;
}

double average(int grades[], int gradesLength)
{
    double sum = 0.0;
    for(int i = 0; i < gradesLength; i ++)
    {
        sum += grades[i];
    }
    return sum / gradesLength;
}

double variance(int grades[], int gradesLength)
{
    double sum = 0.0;
    double variance;
    for(int i = 0; i < gradesLength; i ++)
    {
        sum += (grades[i] - average(grades, gradesLength)) * (grades[i] - average(grades, gradesLength));
    }
    variance = sum / gradesLength;
    return variance;
}