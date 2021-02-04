
typedef struct
{
    int ele;
    struct Ele *next;
} Ele;

typedef Ele *Element;

typedef struct
{
    int count;
    Element head;
    Element tail;
} Que;

// pointer to a single Que object to pass by reference everywhere
typedef Que *Queue;

typedef enum
{
    FALSE,
    TRUE

} Boolean;

Queue newQ();                   // returns an empty Queue
Boolean isEmptyQ(Queue q);      // tests whether q is empty
Queue delQ(Queue q);            // deletes the element from the front of the Queue; returns the modified Queue
Element front(Queue q);         // returns the element from the front of the Queue;
Queue addQ(Queue q, Element e); // adds e to the rear of the Queue; returns the modified Queue
int lengthQ(Queue q);           // returns the length of the Queue
void printQ(Queue q);
