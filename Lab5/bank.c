#include "bank.h"
#include <stdlib.h>
#include <string.h>

int numAccounts = 5;

void shuffle(account *array, int n)
{
    // function to randomly shuffle the bank array
    int i;
    for (i = 0; i < 500; i++)
    {
        int j = i + rand() / (RAND_MAX / (n - i) + 1);
        account t = array[j];
        array[j] = array[i];
        array[i] = t;
    }
}

account *readRecordsFromFile(FILE *fptr)
{
    // printf("1\n");
    account *bank = (account *)malloc(numAccounts * sizeof(account));
    // printf("1\n");

    int idx = 0;

    char line[100];
    while (fscanf(fptr, "\"%[^\"]\"\n", line) != -1)
    {
        // printf("1\n");

        char *endptr;

        account ac;

        // printf("%s\n", line);
        ac.cardNumber = strtoll(strtok(line, ","), &endptr, 10);
        // printf("%llu\n", ac.cardNumber);

        strcpy(ac.bankCode, strtok(NULL, ","));
        // printf("%s\n", ac.bankCode);

        strcpy(ac.expiryDate, strtok(NULL, ","));
        // printf("%s\n", ac.expiryDate);

        strcpy(ac.fname, strtok(NULL, ","));
        // printf("%s\n", ac.fname);

        strcpy(ac.lname, strtok(NULL, ","));
        // printf("%s\n", ac.lname);

        bank[idx] = ac;
        idx++;

        // reallocate bank array if number of elements exceed numAccounts
        if (idx >= numAccounts)
        {
            bank = (account *)realloc(bank, (idx + 1) * sizeof(account));
            if (!bank)
            {
                printf("Error in reallocating!\n");
                exit(0);
            }
        }
    }

    numAccounts = idx;
    return bank;
}

void printDetails(account *bank)
{
    for (int i = 0; i < numAccounts; i++)
    {
        printf("Credit card num: %lld,  Name: %s\n", bank[i].cardNumber, bank[i].fname);
    }
}

account *readNRecordsFromFile(FILE *fptr, int num)
{
    account *bank = (account *)malloc(num * sizeof(account));
    int idx = 0;

    char line[100];
    while (fscanf(fptr, "\"%[^\"]\"\n", line) != -1 && idx < num)
    {
        char *endptr;
        account ac;

        ac.cardNumber = strtoll(strtok(line, ","), &endptr, 10);
        strcpy(ac.bankCode, strtok(NULL, ","));
        strcpy(ac.expiryDate, strtok(NULL, ","));
        strcpy(ac.fname, strtok(NULL, ","));
        strcpy(ac.lname, strtok(NULL, ","));

        bank[idx] = ac;
        idx++;
    }

    numAccounts = idx;

    shuffle(bank, numAccounts);

    return bank;
}