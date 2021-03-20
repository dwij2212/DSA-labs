#include "sort.h"
#include <stdio.h>

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

// int main()
// {
//     int arr[] = {12, 11, 13, 6, 5, 23, 7, 9, 10, 45, 90, 32, 29};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     combineSort(arr, n, 4);
//     printArray(arr, n);

//     return 0;
// }