#include <stdio.h>
#include <stdlib.h>
#include "que.h"

Queue newQ() // returns an empty Queue
{
    Queue q = (Queue)malloc(sizeof(Que));
    q->count = 0;
    q->head = NULL;
    q->tail = NULL;
    return q;
}

Boolean isEmptyQ(Queue q) // tests whether q is empty
{
    if (q->count == 0)
    {
        return TRUE;
    }

    return FALSE;
}

Queue delQ(Queue q) // deletes the element from the front of the Queue; returns the modified Queue
{
    Element temp;
    temp = q->head;
    q->head = temp->next;
    free(temp);
    q->count--;

    return q;
}

Element front(Queue q) // returns the element from the front of the Queue;
{
    Element temp = q->head;
    return temp;
}

Queue addQ(Queue q, Element e) // adds e to the rear of the Queue; returns the modified Queue
{

    if (isEmptyQ(q) == TRUE)
    {
        q->head = e;
        q->tail = e;
    }
    else
    {
        Element temp = q->tail;
        temp->next = e;
        q->tail = e;
    }

    q->count++;
    return q;
}

int lengthQ(Queue q)
{
    return q->count;
}

void printQ(Queue q)
{
    printf("[ ");
    if (q->head == NULL)
    {
        printf("Empty...");
        printf("]");
        return;
    }

    Element cursor = q->head;
    while (cursor->next != NULL)
    {
        printf("(ID %d) ", cursor->ele);
        cursor = cursor->next;
    }
    printf("]");
}