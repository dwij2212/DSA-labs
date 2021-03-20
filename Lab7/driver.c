#include "bisection.h"

int main(int argc, char *argv[])
{
    struct timeval t1, t2;
    int size = atoi(argv[1]);
    double elapsedTime;
    int index = 0;

    FILE *f = fopen(argv[1], "r");
    char name[11];
    int id;

    record *arr = readRecordsFromFile(f, size);
    fclose(f);

    int mid = estimateCutoff(arr);
    printf("Cutoff is at %d\n", mid);

    gettimeofday(&t1, NULL);
    combineSort(arr, size, mid);
    gettimeofday(&t2, NULL);

    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;    // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
    printf("%lfms is the time taken by Combine sort\n", elapsedTime);

    FILE *graphPtr = fopen("output.csv", "a");
    fprintf(graphPtr, "%d,%f\n", size, elapsedTime);
    fclose(graphPtr);

    FILE *fptr = fopen(argv[2], "w");
    for (int i = 0; i < size; i++)
    {
        fprintf(fptr, "%s %d\n", arr[i].name, arr[i].empID);
    }
    fclose(fptr);
}