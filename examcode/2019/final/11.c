#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} Node;
typedef struct linkedList {
    Node *head;
} LinkedList;

void bubbleSortLinkedList(LinkedList *list)
{
    int swapped = 1;
    while(swapped)
    {
        swapped = 0;
        Node* current = list -> head;
        while(current != NULL && current -> next != NULL)
        {
            if(current -> data > current -> next -> data)
            {
                int temp = current -> data;
                current -> data = current -> next -> data;
                current -> next -> data = temp;
                swapped = 1;
            }
        }
        current = current -> next;
    }
}