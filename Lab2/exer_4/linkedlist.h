#include <stdio.h>

// structure definitions
// structure of a linked list node. It contains an element
struct node
{
    int element;
    struct node *next;
};
/* structure of a linked list / head. It stores the count of number of elements
in the list and also a pointer link to the first node of the list. */
struct linkedList
{
    int count;
    struct node *first;
};

// function declarations

/* inserts a given element at the beginning of the list */
void insertFirst(struct linkedList *head, int ele);

/* deletes the first element of the list and returns pointer to the deleted
node. */
struct node *deleteFirst(struct linkedList *head);

/* prints all the elements in the list */
void printList(struct linkedList *head);

/* searches for a given element in the linked list. Returns 1 if found, 0
otherwise. */
int search(struct linkedList *head, int ele);

/* deletes the first node in the list that contains the element = ele and
retuns it. If the element is not found it returns an error message saying
element not found. */
struct node *delete (struct linkedList *head, int ele);

/* Prints contents of list to given file (filename specified as 2nd arguement) */
void printListToFile(struct linkedList *head, char *filename);
