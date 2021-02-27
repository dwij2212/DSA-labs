#include "ex2.h"

int *insertionSortPointer;

void insertInOrder(account *arr, int index)
{

    // keep track of the last node
    account *temp = &arr[index - 1];

    while (arr != temp) // iterate till temp reaches initial node
    {
        account *prev = temp - 1;
        if (prev->cardNumber > temp->cardNumber) // if node before temp is smaller than itself then swap
        {
            account a = *prev;
            *prev = *temp;
            *temp = a;
        }
        temp--;
    }
}

account *insertionSort(account *arr, int size)
{
    if (size > 1)
    {
        insertionSort(arr, size - 1);
    }
    else if (size == 1)
    {
        int dummy;
        insertionSortPointer = &dummy;
    }

    insertInOrder(arr, size);

    return arr;
}