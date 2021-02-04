#include "multiQ.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

// IMPORTANT NOTE:
// I have implemented this lab in such a way that a task whose priority
// is 1 will be at a higher priority than a task whose priority is 5.
// A task whose priority is 1 is interpreted as the FIRST PRIORITY.
// A task whose priority is 2 is interpreted as the SECOND PRIORITY.
// and so on....

MultiQ mq;

MultiQ loadData(FILE *f);
MultiQ testDel(int num);

int main(int argc, char *argv[])
{
    struct timeval t1, t2;
    double elapsedTime;

    FILE *fileptr;
    if (argc == 2)
    {

        fileptr = fopen(argv[1], "r");
        mq = loadData(fileptr);

        printf("Before deletion....\n");
        printMultiQ(mq);
        gettimeofday(&t1, NULL);
        mq = testDel(20);
        gettimeofday(&t2, NULL);

        printf("\n\nAfter deletion....\n");
        printMultiQ(mq);
        elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
        elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
        printf("Total time is %f ms.\n", elapsedTime);
    }

    return 0;
}

MultiQ loadData(FILE *fptr)
{

    if (fptr == NULL)
    {
        printf("Error opening file\n");
        exit(0);
    }

    mq = createMQ(MAX);

    if (mq == NULL)
    {
        printf("Error");
    }

    while (!feof(fptr))
    {
        int id, pri;
        fscanf(fptr, "%d,%d", &id, &pri);

        Priority p;
        p.pri_no = pri;
        Task t;
        t.id = id;
        t.pri = p;

        mq = addMQ(mq, t);
    }

    return mq;
}

MultiQ testDel(int num)
{
    while (num--)
    {
        mq = delNextMQ(mq);
    }

    return mq;
}