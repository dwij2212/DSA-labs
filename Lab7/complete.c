#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

typedef struct record
{
    char name[10];
    int empID;
} record;

record *readRecordsFromFile(FILE *fptr, int size)
{
    record *db = (record *)malloc(size * (sizeof(record)));

    int id;
    char name[10];
    int i = 0;

    // Read lines
    while (fscanf(fptr, "%s %d\n", name, &id) != EOF)
    {

        strcpy(db[i].name, name);
        db[i].empID = id;
        i++;
    }

    return db;
}

void displayRecords(record *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("EMP ID: %d,  Name: %s\n", arr[i].empID, arr[i].name);
    }
}

void writeRecordsToFile(record *arr, char *filename, int size)
{
    FILE *fptr = fopen(filename, "wa");
    for (int i = 0; i < size; i++)
    {
        fprintf(fptr, "%s %d", arr[i].name, arr[i].empID);
    }

    fclose(fptr);
}

void swap(record *a, record *b)
{
    record temp = *a;
    *a = *b;
    *b = temp;
}

int partition(record arr[], int l, int h)
{
    record x = arr[h];
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++)
    {
        if (arr[j].empID <= x.empID)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}

void iterativeQuickSort(record arr[], int l, int h, int S)
{
    if (S < 1)
    {
        S = 0;
    }

    // Create an auxiliary stack
    int stack[h - l + 1];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = h;

    // Keep popping from stack while is not empty
    while (top >= 0)
    {
        // Pop h and l
        h = stack[top--];
        l = stack[top--];

        // Set pivot element at its correct position
        // in sorted array
        int p = partition(arr, l, h);

        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > l + S)
        {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 + S < h)
        {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}

void iterativeInsertionSort(record arr[], int n)
{
    int i, j;
    record key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are 
        greater than key, to one position ahead 
        of their current position */
        while (j >= 0 && arr[j].empID > key.empID)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void combineSort(record arr[], int n, int S)
{
    iterativeQuickSort(arr, 0, n - 1, S);
    iterativeInsertionSort(arr, n);
}

void copyArray(record temp[], record arr[], int size)
{
    // int arrSize = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        temp[i] = arr[i];
    }
}

double *testRun(record arr[], int size)
{
    double *values = malloc(sizeof(double) * 2);
    record *temp = (record *)malloc(sizeof(record) * size);
    struct timeval t1, t2;

    // call insertion sort on temp
    copyArray(temp, arr, size);

    gettimeofday(&t1, NULL);
    iterativeInsertionSort(temp, size);
    gettimeofday(&t2, NULL);

    values[0] = (t2.tv_sec - t1.tv_sec) * 1000.0;
    values[0] += (t2.tv_usec - t1.tv_usec) / 1000.0;

    // call quick sort on temp
    copyArray(temp, arr, size);

    gettimeofday(&t1, NULL);
    iterativeQuickSort(temp, 0, size - 1, 0);
    gettimeofday(&t2, NULL);

    values[1] = (t2.tv_sec - t1.tv_sec) * 1000.0;
    values[1] += (t2.tv_usec - t1.tv_usec) / 1000.0;
    free(temp);
    return values;
}

int estimateCutoff(record arr[])
{
    int mid, min = 10, max = 1000;
    double *v1 = testRun(arr, min);
    double *v2 = testRun(arr, max);

    double qstime, istime;
    do
    {
        mid = (min + max) / 2;
        double *v = testRun(arr, mid);

        if (v[0] > v[1])
        {
            max = mid;
        }
        else
        {
            min = mid;
        }
        qstime = v[1];
        istime = v[0];
        free(v);

        if (max == mid && mid == min)
        {
            printf("Cannot converge anymore.\n");
            break;
        }

    } while (qstime - istime > 0.001 || istime - qstime > 0.001);

    printf("tt1 values:\t\t InsSort-%f\t QuickSort-%f\n", v1[0], v1[1]);
    printf("tt2 values:\t\t InsSort-%f\t QuickSort-%f\n", v2[0], v2[1]);

    free(v1);
    free(v2);

    return mid;
}

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