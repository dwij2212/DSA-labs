#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

// pushes element at top
void push(struct linkedList *top, int ele)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->element = ele;

    temp->next = top->first;
    top->first = temp;
}

struct node *pop(struct linkedList *top)
{
    struct node *temp = top->first;
    top->first = temp->next;
    return temp;
}