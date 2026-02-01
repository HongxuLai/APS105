#include <stdio.h>
int main()
{
    int num;
    printf("Enter an encrypted 4-digit combination: ");
    scanf("%d", &num);
    int a;
    a = num / 1000;
    int b;
    b = (num % 1000) / 100;
    int c;
    c = (num % 100) / 10;
    int d;
    d = num % 10;
    int new_num;
    new_num = d * 1000 + (9 - b) * 100 + (9 - c) * 10 + a;
    printf("The real combination is: %d", new_num);
}
