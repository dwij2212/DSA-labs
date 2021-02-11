#ifndef LL_H
#define LL_H

typedef struct node
{
    int ele;
    struct node *next;
} node;

typedef struct ll
{
    struct node *head;
    struct node *tail;
    int size;
} LinkedList;

#endif