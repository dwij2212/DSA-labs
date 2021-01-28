#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

void insertFirst(struct linkedList *head, int ele)
{
    //create a node
    struct node *link = (struct node *)malloc(sizeof(struct node));
    /* by this you are creating a node whose address is being stored in the link pointer. */
    link->element = ele;

    //point it to old first node
    link->next = head->first;

    //point first to new first node
    head->first = link;
    head->count--;
}

//delete first item
struct node *deleteFirst(struct linkedList *head)
{
    struct node *temp = head->first;
    head->first = temp->next;
    return temp;
}

void printList(struct linkedList *head)
{
    struct node *ptr = head->first;
    printf("[ ");
    //start from the beginning
    while (ptr != NULL)
    {
        printf("%d, ", ptr->element);
        ptr = ptr->next;
    }
    printf(" ]\n");
}

int search(struct linkedList *head, int ele)
{
    struct node *cursor = head->first;

    while (cursor)
    {
        if (cursor->element == ele)
        {
            return 1;
        }
        cursor = cursor->next;
    }

    return 0;
}

void printListToFile(struct linkedList *head, char *filename)
{
    struct node *ptr = head->first;
    FILE *fptr;
    fptr = fopen(filename, "w");
    if (!fptr)
    {
        printf("error in writing to file! \n");
        exit(0);
    }

    fprintf(fptr, "%s", "[ ");

    while (ptr != NULL)
    {
        fprintf(fptr, "%d, ", ptr->element);
        ptr = ptr->next;
    }
    fprintf(fptr, "%s", "]");
    fclose(fptr);
}

struct node *delete (struct linkedList *head, int ele)
{
    struct node *cursor = head->first;

    while (cursor)
    {
        if ((cursor->next)->element == ele)
        {
            struct node *temp = cursor->next;
            cursor->next = temp->next;
            return temp;
        }
        cursor = cursor->next;
    }

    printf("No such element found!\n");
    return NULL;
}