#include <stdio.h>
#include <stdlib.h>
// Struct for a node in a linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Struct for the linked list
typedef struct list {
   Node* head;
} LinkedList;

LinkedList* mergeLists(LinkedList* left, LinkedList* right)
{
    LinkedList* merged = malloc(sizeof(LinkedList));
    if (merged == NULL) {
        return NULL;
    }
    merged->head = NULL;

    Node* c1 = left -> head;
    Node* c2 = right -> head;
    Node* tail = NULL;

    while(c1 != NULL && c2 != NULL)
    {
        Node* nextNode;
        if(c1 -> data <= c2 -> data)
        {
            nextNode = c1;
            c1 = c1 -> next;
        }
        else
        {
            nextNode = c2;
            c2 = c2 -> next;
        }

        if(merged -> head == NULL)
        {
            merged -> head = nextNode;
            tail = nextNode;
        }
        else
        {
            tail -> next = nextNode;
            tail = nextNode;
        }
    }

    if(c1 != NULL)
    {
        if(merged -> head == NULL)
        {
            merged -> head = c1;
        }
        else tail -> next = c1;
    }
    
    if(c2 != NULL)
    {
        if(merged -> head == NULL)
        {
            merged -> head = c2;
        }
        else tail -> next = c2;
    }

    left -> head = NULL;
    right -> head = NULL;
}