#include <stdio.h>
#define ARRAY_SIZE 17

void printArray(int array[]); 
void initializeArray(int aliveIndex, int array[]);
int getRuleOutcome(int rule, int left, int center, int right);
void calculateNextState(int currentArray[], int nextArray[], int rule);
void simulateGenerations(int iterations, int array[], int rule);

int main(void)
{
    int aliveIndex;
    int rule;
    int iterations;
    printf("Enter input: ");
    scanf("%d %d %d", &aliveIndex, &rule, &iterations);
    int initialarray[17] = {0};
    initializeArray(aliveIndex, initialarray);
    simulateGenerations(iterations, initialarray, rule);
    return 0;
}

/* print array, using 1/0 to represent cell's state, 1 -> '*', 0 -> ' ' */
void printArray(int array[])
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (array[i] == 1) printf("*");
        if (array[i] == 0) printf(" ");
    }
}

/* all elements equal to 0 except the aliveIndex, which is set to 1 */
void initializeArray(int aliveIndex, int array[])
{
    array[aliveIndex] = 1;
}

/* convert rule into binary and convert LCR to decimal */
int getRuleOutcome(int rule, int left, int center, int right)
{
    int bin[8] = {0};
    for(int i = 0; i <= 7; i++) // get rule's binary representation
    {
        bin[i] = rule % 2;
        rule /= 2;
    }

    int decimal = left * 4 + center * 2 + right; // get LCR's decimal representation
    int new_center = bin[decimal];
    return new_center;
}

/* change currentArray to nextArray using getruleOutcome and rule, 
   using fixed conditions to get left and right */
void calculateNextState(int currentArray[], int nextArray[], int rule)
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        int left = 0;
        int right = 0;
        int center = currentArray[i];

        if (i - 1 >= 0) left = currentArray[i-1];
        if (i + 1 < ARRAY_SIZE) right = currentArray[i+1];
        
        nextArray[i] = getRuleOutcome(rule, left, center, right);
    }
}

/* loop and call calculateNextState() 
   and print the generated array for iterations number of generations */
void simulateGenerations(int iterations, int array[], int rule)
{
    int currentArray[17] = {0};
    int nextArray[17] = {0};
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        currentArray[i] = array[i];
    }
    for (int m = 0; m < iterations; m++)
    {
        calculateNextState(currentArray, nextArray, rule);
        printArray(currentArray);
        printf("\n");
        for (int n = 0; n < ARRAY_SIZE; n++) currentArray[n] = nextArray[n];
    }

}