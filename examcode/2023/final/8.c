#include <stdio.h>

struct Node
{
    double resistance;
    double reactance;
    double voltage;
    struct Node *next;
};

double calculateMagnitude (double resistance, double reactance)
{
    return sqrt(pow(resistance, 2) + pow(reactance, 2));
}

double equivalentMagnitude(struct Node *ptr, int n)
{
    int sum = 0;
    struct Node* current = ptr;
    while(current != NULL)
    {
        sum += calculateMagnitude(current -> resistance, current -> reactance);
        current = current -> next;
    }
    return sum;
}