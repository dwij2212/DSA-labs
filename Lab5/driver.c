#include "bank.h"
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

int main()
{
    struct timeval t1, t2;
    double elapsedTime;
    srand(time(0));

    int size = 10;
    for (int i = 0; i < 3; i++)
    {
        char *temp = malloc(sizeof(char) * 100);
        sprintf(temp, "%d", size);
        FILE *fptr = fopen(temp, "r");

        if (fptr == NULL)
        {
            printf("Error opening file\n");
        }

        gettimeofday(&t1, NULL);
        account *bank = readRecordsFromFile(fptr);
        gettimeofday(&t2, NULL);

        elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
        elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
        printf("Total time taken for %d inputs is testCyclic %f ms.\n", i, elapsedTime);

        // printf("INMAIn\n");
        // printDetails(bank);
        // printf("INMAIn\n");
        free(bank);

        size *= 10;
    }
}