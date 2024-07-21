//
// Created by Michal Roziel on 18.07.24.
//
#include <stdio.h>
#include "string.h"
#include "workerDetails.h"

#define WORKER_LIMIT 50

worker mitarbeiter[WORKER_LIMIT];
int numberOfWorkers = 0;

int findPositioninArray(char *name)
{

    int index = -1;

    for (int i = 0; i < numberOfWorkers; i++)
    {
        if (strcmp(mitarbeiter[i].name, name) == 0)
        {
            index = i;
            break;
        }
    }

    return index;
}

void printWorker(int index)
{

    if (index < 0 || index >= numberOfWorkers)
    {

        printf("worker not found!");
    }
    else
    {
        printf("their stats are:\n\n name: %s \n age: %d \n branch: %s \n salary: %.2f \n", mitarbeiter[index].name, mitarbeiter[index].age, mitarbeiter[index].branch, mitarbeiter[index].salary);
    }
}

void addMitarbeiter()
{
    printf("Welcome to the add worker menu!\n");

    if (numberOfWorkers >= 50)
    {
        printf("Maximum Limit of workers reached! Consider removing someone..");

        return;
    }

    char name[32];
    int age;
    char branch[32];
    float salary;

    // getting new workers stats from user input

    // name
    printf("Please enter the worker's name: ");
    scanf("%31s", name); // use %31s to limit input length and avoid buffer overflow

    // age
    printf("Please enter the worker's age: ");
    scanf("%d", &age);

    // branch
    printf("Please enter the worker's branch: ");
    scanf("%31s", branch);

    // salary
    printf("Please enter the worker's salary: ");
    scanf("%f", &salary);

    worker workerToBeAdded; // create a new worker struct

    strcpy(workerToBeAdded.name, name);
    workerToBeAdded.age = age;
    strcpy(workerToBeAdded.branch, branch);
    workerToBeAdded.salary = salary;

    mitarbeiter[numberOfWorkers] = workerToBeAdded;
    numberOfWorkers++;

    printf("\n worker %d has been added to the lineup!\n", numberOfWorkers);
    printf("their stats are:\n\n name: %s \n age: %d \n branch: %s \n salary: %.2f \n", workerToBeAdded.name, workerToBeAdded.age, workerToBeAdded.branch, workerToBeAdded.salary);
}

void deleteMitarbeiter(char *name)
{

    int index = findPositioninArray(name);

    //  [ m1, m2, m3, m4, m5, m6, m7, m8, m9 ]
    //  [ m1, m2, m9, m4, m5, m6, m7, m8, m9 ]
    // numberofWorkers -- -> just iterate up to m8

    if (index == -1)
    {
        printf("no worker found!...");
        return;
    }

    mitarbeiter[index] = mitarbeiter[numberOfWorkers - 1];
    numberOfWorkers--;
}
void editMitarbeiter(char *name)
{
    int index = findPositioninArray(name);
    int choice;

    if (index == -1)
    {
        printf("no worker found!...");
        return;
    }

    printf("Please select what to edit:\n");
    printf("1. the workers age");
    printf("2. the workers branch");
    printf("3. the workers salary");
    printf("4. do not edit anything");

    scanf("%d", &choice);

    int newAge;
    char newBranch[32];
    float newSalary;

    switch (choice)
    {

    case 1:

        printf("Please type in the new age");
        scanf("%d", &newAge);

        mitarbeiter[index].age = newAge;

        break;

    case 2:

        printf("Please type in the new branch");
        scanf("%31s", newBranch);

        strcpy(mitarbeiter[index].branch, newBranch);

        break;

    case 3:

        printf("Please type in the new salary");
        scanf("%f", &newSalary);

        mitarbeiter[index].salary = newSalary;

        return;

    case 4:
        return;

    default:
        return;
    }
}

void queryMitarbeiter(char *name)
{
    int index = findPositioninArray(name);

    printWorker(index);
}

void printAllMitarbeiter()
{
    for (int i = 0; i < numberOfWorkers; ++i)
    {

        printWorker(i);
    }
}
