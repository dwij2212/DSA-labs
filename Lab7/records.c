#include "records.h"
#include <string.h>

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