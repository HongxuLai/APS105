#include <stdio.h>

void printHollowTriangle(int lines);

int main(void)
{
    printHollowTriangle(10);
    return 0;
}

void printHollowTriangle(int lines)
{
    int row;
    int col;
    for(row = 1; row <= lines; row ++)
    {
        for(col = 1; col <= row; col ++)
        {
            if(col == 1 || col == row || row == lines)
            {
                printf("*");
            }
            else printf(" ");
        }
        printf("\n");
    }
}