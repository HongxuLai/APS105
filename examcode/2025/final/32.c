#include <stdio.h>
#include <stdlib.h>

// Struct for a node in the doubly linked list
typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
} Node;

// Struct for the linked list
typedef struct {
    Node* head;
    Node* tail;
} DoublyLinkedList;

void insertAfterNode(DoublyLinkedList* list, Node* prevNode, int val);

int main(void) {
  DoublyLinkedList listA;
  Node a1 = {1, NULL, NULL};
  Node a2 = {2, &a1, NULL};
  a1.next = &a2;
  listA.head = &a1;
  listA.tail = &a2;
  insertAfterNode(&listA, &a2, 7);
  return 0;
}
void insertAfterNode(DoublyLinkedList* list, Node* prevNode, int val)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL)
    {
        return;
    }
    newNode->data = val;
    newNode->prev = prevNode;
    newNode->next = prevNode->next;

    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    } 
    else {
        list->tail = newNode;
    }
}