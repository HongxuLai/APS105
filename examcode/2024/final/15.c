#include <stdio.h>
#include <stdbool.h>

typedef struct node {
int data;
struct node* next;
} Node;
typedef struct linkedList {
Node* head;
} LinkedList;

void fixOrder(LinkedList* list) 
{
    Node* current = list -> head;
    Node* prev = NULL;

    if (list == NULL || list->head == NULL || list->head->next == NULL) {
        return;
    }

    while(current -> next != NULL && current -> data <= current -> next -> data)
    {
        prev = current;
        current = current -> next;
    }

    if(current -> next == NULL) return;
    Node* temp = current -> next;
    if(prev == NULL)
    {
        list -> head = temp;
    }
    else prev -> next = temp;

    current -> next = temp -> next;
    temp -> next = current;
    
}