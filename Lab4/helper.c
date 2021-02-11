#include "helper.h"
#include <stdio.h>
#include <time.h>

extern int space;

LinkedList *createList(int n)
{
    // randomly generates numbers and creates a linked list
    LinkedList *ll = (LinkedList *)myalloc(sizeof(LinkedList));
    ll->head = NULL;
    ll->tail = NULL;
    ll->size = 0;

    // set seed as current time

    if (ll == NULL)
    {
        printf("List could not be created.\n");
        return NULL;
    }

    node *cursor;

    // iterate n times to create a list
    while (n--)
    {
        node *temp = (node *)myalloc(sizeof(node));

        // generates random numbers between 1-1000
        temp->ele = rand() % 1000 + 1;
        temp->next = NULL;

        // trivial case when list is empty
        if (ll->size == 0)
        {
            ll->head = temp;
            ll->tail = temp;
            (ll->size)++;

            cursor = temp;
        }

        // insert new node into list
        else
        {
            cursor->next = temp;
            cursor = temp;
            (ll->size)++;
        }
    }

    // last element since cursor moves over until the last one
    ll->tail = cursor;

    return ll;
}

LinkedList *createCycle(LinkedList *ll)
{
    int cycle = rand() % 2;

    if (cycle)
    {
        int r = rand() % ll->size;

        node *cursor = ll->head;
        while (r--)
        {
            cursor = cursor->next;
        }

        (ll->tail)->next = cursor;
        printf(" created a cycle successfulyy.\n");
    }
    else
    {
        printf(" No cycle created.\n");
    }
    return ll;
}

void printList(LinkedList *ll)
{
    node *cursor = ll->head;

    printf("location of head - %p\n", cursor);

    if (cursor == NULL)
    {
        printf("Empty list.\n");
        return;
    }

    while (cursor != NULL)
    {
        printf("%d, location of next node - %p\n", cursor->ele, cursor->next);
        cursor = cursor->next;
    }

    printf("location of tail - %p\n", ll->tail);
}

void *myalloc(size_t size)
{
    void *temp = malloc(size);
    space += size;
    return temp;
}

void myfree(void *ptr, size_t size)
{
    free(ptr);
    space -= size;
}

void emptyList(LinkedList *ll)
{
    node *cursor = ll->head;
    node *temp;
    if (cursor == NULL)
    {
        printf("Empty list.\n");
    }

    int i = 0;
    while (cursor != NULL)
    {
        temp = cursor;
        cursor = cursor->next;

        myfree(temp, sizeof(node));
    }

    myfree(ll, sizeof(LinkedList));
}