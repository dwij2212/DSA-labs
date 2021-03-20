#include "bisection.h"

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