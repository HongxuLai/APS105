#include <stdio.h>

int main()
{
    int num;
    int times = 0;
    do
    {
        printf("Input an integer (0 to stop): ");
        scanf("%d", &num);

        if (num == 0) break;

        int restnum = num;
        int threetimes = 0;

        if (restnum < 0) restnum = -restnum;
        while (restnum != 0)
        {
            int lastnum = restnum % 10;
            if (lastnum == 7) threetimes += 1;
            restnum /= 10;
        }
        if (threetimes >= 3) times += 1;
    } while(num != 0);
    printf("You entered %d pretty number(s)!\n", times);
    return 0;
}