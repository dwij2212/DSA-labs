#include "helper.h"
#include <stdio.h>
#include "cycle.h"

int space = 0;
int main(int argc, char const *argv[])
{
    LinkedList *ll = createList(10);
    printList(ll);
    // printf("Space full: %d\n", space);

    ll = createCycle(ll);

    // commented out because this can be only executed if there is no cycle
    // emptyList(ll);
    // printf("Space full: %d\n", space);
    int c = testCyclic(ll);
    if (c)
    {
        printf("Cycle detected.\n");
    }

    return 0;
}
