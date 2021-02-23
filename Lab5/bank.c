#include "bank.h"
#include <stdlib.h>
#include <string.h>

int numAccounts = 5;

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