#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct paper {
    char *lastName;
    struct paper *next;
} Paper;
typedef struct linkedList {
    Paper *head;
} LinkedList;

void printList(LinkedList* list, int i) {
    Paper* current = list->head;
    if (current != NULL) 
    {
        printf("%c: ", i + 'A');
    }
    while (current != NULL) 
    {
        printf("%s ", current->lastName);
        current = current->next;
    }
    if (list->head != NULL) 
    {
        printf("\n");
    }
}
void sortPapers(LinkedList* originalPile, LinkedList sortedPile[])
{
    Paper* current = originalPile -> head;
    while(current != NULL)
    {
        int i = current -> lastName[0] - 'A';
        Paper* first = current;
        current = current -> next;
        first -> next = NULL;
        if(sortedPile[i].head == NULL || strcmp(first -> lastName, sortedPile[i].head -> lastName) <= 0)
        {
            first -> next =sortedPile[i].head;
            sortedPile[i].head = first;
        }
        else
        {
            Paper* temp = sortedPile[i].head;
            while(temp -> next != NULL && strcmp(temp -> next -> lastName, first -> lastName) <= 0 )
            {
                temp = temp -> next;
            }
            if(temp -> next == NULL)
            {
                temp -> next = first;
            }
            else
            {
                first -> next = temp -> next;
                temp -> next = first;
            }
        }
        originalPile->head = NULL;
    }
}