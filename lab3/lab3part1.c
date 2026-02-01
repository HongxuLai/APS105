#include <stdio.h>
int main()
{
    int threshold;
    int observed;
    const int water = 100;
    const int mercury = 357;
    const int copper = 1187;
    const int silver = 2193;
    const int gold = 2660;
    printf("Enter the threshold in Celsius: ");
    scanf("%d", &threshold);
    printf("Enter the observed boiling point in Celsius: ");
    scanf("%d", &observed);
    if (water - threshold <= observed && observed <= water + threshold)
    {
        printf("The substance you tested is: Water\n");
    }
    else if (mercury - threshold <= observed && observed <= mercury + threshold)
    {
        printf("The substance you tested is: Mercury\n");
    }
    else if (copper - threshold <= observed && observed <= copper + threshold)
    {
        printf("The substance you tested is: Copper\n");
    }
    else if (silver - threshold <= observed && observed <= silver + threshold)
    {
        printf("The substance you tested is: Silver\n");
    }
    else if (gold - threshold <= observed && observed <= gold + threshold)
    {
        printf("The substance you tested is: Gold\n");
    }
    else
    {
        printf("Substance unknown.\n");
    }
    return 0;
}