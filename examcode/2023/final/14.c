#include <stdio.h>
#include <stdbool.h>

typedef struct node 
{
    int data;
    struct node *next;
} Node;

typedef struct linkedList 
{
    Node *head;
} LinkedList;

void insertSequence(LinkedList *list, LinkedList *seq)
{
    Node* current = list -> head;
    Node* prev = NULL;
    Node* seqHead = seq -> head;
    Node* seqTail = seq -> head;

    if (seq -> head == NULL) return;
    if (list -> head == NULL) list -> head = seq -> head;

    while(seqTail -> next != NULL)
    {
        seqTail = seqTail -> next;
    }

    while(current != NULL && current -> data < seqHead -> data)
    {
        prev = current;
        current = current -> next;
    }

    if(prev == NULL)
    {
        seqTail -> next = list -> head;
        list -> head = seqHead;
    }
    else
    {
        prev -> next = seqHead;
        seqTail -> next = current;
    }
}