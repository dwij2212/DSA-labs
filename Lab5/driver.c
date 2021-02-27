#include "bank.h"
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "ex2.h"

extern int *insertionSortPointer;

int main()
{
    struct timeval t1, t2;
    double elapsedTimeRead, elapsedTimeSort;
    srand(time(0));

    int size = 10;
    for (int i = 0; i < 5; i++)
    {
        // programmatically open each input file
        char *temp = malloc(sizeof(char) * 100);
        sprintf(temp, "%d", size);
        FILE *fptr = fopen(temp, "r");

        if (fptr == NULL)
        {
            printf("Error opening file\n");
        }

        gettimeofday(&t1, NULL);
        account *bank = readRecordsFromFile(fptr); // create a bank array containing array of account details
        gettimeofday(&t2, NULL);

        elapsedTimeRead = (t2.tv_sec - t1.tv_sec) * 1000.0;
        elapsedTimeRead += (t2.tv_usec - t1.tv_usec) / 1000.0;
        printf("Total time taken for %d inputs in reading is %f ms.\n", size, elapsedTimeRead);

        // printDetails(bank);

        int dummy;
        int *mainPointer = &dummy;
        gettimeofday(&t1, NULL);
        bank = insertionSort(bank, size); // size here is the variable which gets multipled by 10 on each iteration
        gettimeofday(&t2, NULL);

        int stackSpace = (int)(mainPointer - insertionSortPointer);

        elapsedTimeSort = (t2.tv_sec - t1.tv_sec) * 1000.0;
        elapsedTimeSort += (t2.tv_usec - t1.tv_usec) / 1000.0;
        printf("Total time taken for %d inputs in sorting is %f ms.\n", size, elapsedTimeSort);

        // uncomment this for small arrays to see sorted order
        // printDetails(bank);

        free(bank);
        free(temp);
        fclose(fptr);
        size *= 10;
    }
}
