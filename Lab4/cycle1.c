#include "cycle.h"
#include <stdio.h>

int testCyclic(LinkedList *ll)
{

    if (ll->size < 2)
    {
        printf("No cycles trivial case.\n");
        return 0;
    }

    else if (ll->size == 2)
    {
        node *head = ll->head;
        node *tail = ll->tail;

        if (tail->next == head)
        {
            return 1;
        }
    }
    else
    {
        node *hare, *tort;

        hare = ll->head;
        tort = ll->head;

        while (hare != tort || hare != NULL)
        {
            if (tort->next == NULL || (hare->next == NULL) || (hare->next)->next == NULL)
            {
                printf("No cycles.\n");
                return 0;
            }

            tort = tort->next;
            hare = (hare->next)->next;

            if (hare == tort && hare != NULL)
            {
                return 1; // cycle found
            }
        }
    }

    return 0;
}