#include <stdio.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

typedef struct linkedList {
  Node *head;
} LinkedList;

void printDuplicates(LinkedList* list)
{
    if(list -> head == NULL) return;
    Node* current = list -> head;
    while(current != NULL)
    {
        Node* temp = current;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
            if(temp -> data == current -> data)
            {
                printf("%d ", current -> data);
                break;
            }
        }
        current = current -> next;
    }
}