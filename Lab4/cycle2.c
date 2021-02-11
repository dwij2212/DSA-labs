#include "cycle.h"
#include <stdio.h>

LinkedList *reverseList(LinkedList *ll)
{
    if (ll->size < 2)
    {
        return ll;
    }
    else
    {
        node *pre = (ll->head);
        node *cursor = pre->next;
        pre->next = NULL;

        while (cursor != NULL)
        {
            // reversal process
            node *temp = cursor->next;
            cursor->next = pre;
            pre = cursor;
            cursor = temp;

            if (cursor == ll->head)
            {
                printf("Detected cycle using reversal.\n");
                return ll;
            }
        }
        printf("No cycle.\n");
    }
}