#include <stdio.h>
#include <stdbool.h>

typedef struct node {
int data;
struct node *next;
} Node;

typedef struct linkedList {
Node *head;
} LinkedList;

bool isCycle(LinkedList* list)
{
    if (list == NULL || list->head == NULL) 
    {
        return false;
    }
    Node* current = list -> head;
    while(current != NULL)
    {
        if(current -> next == list -> head)
        {
            return true;
        }
        current = current -> next;
    }
    return false;
}
