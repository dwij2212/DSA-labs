#include "helper.h"
#include <stdio.h>
#include "cycle.h"
#include <sys/time.h>
#include <time.h>

int space = 0;
int main(int argc, char const *argv[])
{
    struct timeval t1, t2;
    double elapsedTime;
    srand(time(0));

    int size_steps = 8;
    int list_size = 1;
    while (size_steps--)
    {
        LinkedList *ll = createList(list_size);
        printf("List of size %d created.\n", list_size);
        printf("Attempting to create a cycle -----");
        ll = createCycle(ll);

        gettimeofday(&t1, NULL);
        int c = testCyclic(ll);
        gettimeofday(&t2, NULL);

        // error while emptying cyclic list
        // emptyList(ll);
        // printf("Emptying list.\n");

        elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
        elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
        printf("Total time taken for testCyclic %f ms.\n", elapsedTime);

        printf("Total heap space utilized: %d\n\n\n", space);

        FILE *fp = fopen("obs.csv", "a");

        if (c)
        {
            printf("Cycle detected.\n");
            fprintf(fp, "%d,Cycle Detected,%f,%d\n", list_size, elapsedTime, space);
        }
        else
        {
            printf("No cycle detected.\n");
            fprintf(fp, "%d,No Cycle Detected,%f,%d\n", list_size, elapsedTime, space);
        }

        fclose(fp);
        list_size *= 10;
    }

    return 0;
}
