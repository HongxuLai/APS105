#include <stdio.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct linkedlist {
    Node *head;
    Node *tail;
} LinkedList;

void remove(LinkedList *list, int value)
{
    Node* current = list -> head;
    Node* prev = NULL;
    while(current != NULL && current -> data != value)
    {
        prev = current;
        current = current -> next;
    }
    if(current == NULL) return;
    if(prev == NULL)
    {
        list -> head = current -> next;
        if(list -> tail == current)
        {
            list -> tail = current -> next;
        }
    }
    else
    {
        prev -> next = current -> next;
        if(list -> tail = current)
        {
            list -> tail = prev;
        }
    }
    free(current);
}