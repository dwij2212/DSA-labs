#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Create a file pointer and open the file read as command line argument.
    FILE *fileptr = fopen(argv[1], "r");
    // Declare a pointer to a linked list (head) and allocate memory to it.
    struct linkedList *head = (struct linkedList *)malloc(sizeof(struct linkedList));

    // In a loop read the file and insert elements into the linkedList.
    while (!feof(fileptr))
    {
        // read the next element and store into the temp variable.
        int temp;
        fscanf(fileptr, "%d ", &temp);
        // insert temp into the stack.
        push(head, temp);
    }

    // close the file pointer
    fclose(fileptr);

    // print some elements which are popped off
    struct node *temp;

    temp = pop(head);
    printf("%d\n", temp->element);
    free(temp);

    temp = pop(head);
    printf("%d\n", temp->element);
    free(temp);

    temp = pop(head);
    printf("%d\n", temp->element);
    free(temp);
}