#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node
{
    int ID;
    char name[100];
    int severity;
    struct node* next;
} Node;

typedef struct list
{
    Node* head;
} Queue;

Node* createNode(int id, char n[], int sev);
bool addFirst(Queue* queue, int id, char n[], int sev);
bool printQueue(Queue* queue);
bool searchRepeated(Queue* queue, int id);
bool insertIntoQueue(Queue* queue, int id, char n[], int sev);
int treatPatient(Queue* queue);
bool removePatient(Queue* queue, int id);
void freeQueue(Queue* queue);

int main()
{
    char op;
    int id;
    char n[100];
    int sev;
    Queue queue;
    queue.head = NULL;
    
    while (scanf(" %c", &op) == 1)
    { 
        if (op == 'A')
        {
            scanf("%d %s %d", &id, n, &sev);
            // add patient function
            if(!searchRepeated(&queue, id)) 
            {
                printf("Error: Patient %d already exists.\n", id);
            }
            else
            {
                insertIntoQueue(&queue, id, n, sev);
                printf("Patient %d Added.\n", id);
            }
        }

        else if (op == 'T')
        {
            // treat patioent function
            int patientId = treatPatient(&queue);
            if(patientId == 0)
            {
                printf("Queue is empty.\n");
            }
            else printf("Patient %d Treated.\n", patientId);
        }

        else if (op == 'R')
        {
            scanf("%d", &id);
            // remove patient function
            if(removePatient(&queue, id))
            {
                printf("Patient %d Removed.\n", id);
            }
            else printf("Error: Patient %d not found.\n", id);
        }

        else if (op == 'D')
        {
            if (!printQueue(&queue))
            {
                printf("Queue is empty.\n");
            }
        }

        else if (op == 'Q')
        {
            // end program
            freeQueue(&queue);
            break;
        }
    }

    return 0;
}

// create a new node, including patient's id, name, severity
Node* createNode(int id, char n[], int sev)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode != NULL)
    {
        newNode -> ID = id;
        strcpy(newNode->name, n);
        newNode -> severity = sev;
        newNode -> next = NULL;
    }
    return newNode;
}

// add a new node at first
bool addFirst(Queue* queue, int id, char n[], int sev)
{
    Node* temp = createNode(id, n, sev);
    if(temp == NULL) return false;
    temp -> next = queue -> head;
    queue -> head = temp;
    return true;
}

// print the queue
bool printQueue(Queue* queue)
{
    Node* current = queue->head;
    if (current == NULL) return false;

    while (current != NULL)
    {
        printf("%s %d\n", current->name, current->severity);
        current = current->next;
    }
    return true;
}

bool searchRepeated(Queue* queue, int id)
{
    Node* current = queue -> head;
    while(current != NULL)
    {
        if(current -> ID != id)
        {
            current = current -> next;
        }
        else return false;
    }
    return true;
}

// insert a node from high secerity to low severity
bool insertIntoQueue(Queue* queue, int id, char n[], int sev)
{
    Node* current = queue -> head;

    // empty queue or the most severe patient, addFirst
    if(queue -> head == NULL || sev > current -> severity)
    {
        return addFirst(queue, id, n, sev);
    }

    // insert the patient by comparing the severity
    while(current -> next != NULL && current -> next -> severity >= sev)
    { 
        current = current -> next;
    }

    Node* temp = createNode(id, n, sev);
    if (temp == NULL) return false;
    temp -> next = current -> next;
    current -> next = temp;
    return true;
}

// treat the most severe patient, same as delete the first node
int treatPatient(Queue* queue)
{
    if(queue -> head != NULL)
    {
        Node* temp = queue -> head -> next;
        int removedID = queue -> head -> ID;
        free(queue -> head);
        queue -> head = temp;
        return removedID;
    }
    else return 0;
}

// search the patient's id and remove it
bool removePatient(Queue* queue, int id)
{
    if (queue -> head == NULL) return false;
    if (queue -> head -> ID == id) 
    {
        treatPatient(queue);
        return true;
    }

    Node* current = queue -> head;
    while(current -> next != NULL && current -> next -> ID != id)
    {
        current = current -> next;
    }

    if (current -> next != NULL)
    {
        Node* temp = current -> next;
        current -> next = temp -> next;
        free(temp);
        return true;
    }
    else return false;
}

// free whole queue
void freeQueue(Queue* queue)
{
    Node* temp;
    Node* current = queue -> head;

    while(current != NULL)
    {
        temp = current;
        current = current -> next;
        free(temp);
    }
    queue->head = NULL;
}