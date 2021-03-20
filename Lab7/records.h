#ifndef RECORDS_H
#define RECORDS_H
#include <stdio.h>
#include <stdlib.h>

typedef struct record
{
    char name[10];
    int empID;
} record;

record *readRecordsFromFile(FILE *fptr, int size);
void displayRecords(record *arr, int size);
void writeRecordsToFile(record *arr, char *filename, int size);
#endif