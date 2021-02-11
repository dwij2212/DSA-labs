#include <stdlib.h>
#include "linkedlist.h"

void *myalloc(size_t size);
void myfree(void *ptr, size_t size);

LinkedList *createList(int n);
LinkedList *createCycle(LinkedList *ll);
void printList(LinkedList *ll);
void emptyList(LinkedList *ll);