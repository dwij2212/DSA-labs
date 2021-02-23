#include <stdio.h>

typedef struct account
{
    unsigned long long cardNumber;
    char bankCode[10];
    char expiryDate[10];
    char fname[20];
    char lname[20];

} account;

account *readRecordsFromFile(FILE *fptr);
void printDetails(account *bank);
