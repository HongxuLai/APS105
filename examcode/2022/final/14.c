#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} Node;
typedef struct linkedList {
    Node *head;
} LinkedList;

void reorder(LinkedList *list)
{
    Node* current = list -> head;
    Node* zeroHead = NULL, *zeroTail = NULL;
    Node* intHead = NULL, *intTail = NULL;
    while(current != NULL)
    {
        Node* next = current -> next;
        current -> next = NULL;
        if(current -> data == 0)
        {
            if(zeroHead == NULL)
            {
                zeroHead = current;
                zeroTail = current;
            }
            else
            {
                zeroTail -> next = current;
                zeroTail = current;
            }
        }
        else
        {
            if(intHead == NULL)
            {
                intHead = current;
                intTail = current;
            }
            else
            {
                intTail -> next = current;
                intTail = current;
            }
        }
        current = next;
    }
    if(zeroHead == NULL)
    {
        list -> head = intHead;
    }
    else
    {
        zeroTail->next = intHead;
        list->head = zeroHead;
    }
}