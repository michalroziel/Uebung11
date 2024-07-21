//
// Created by Michal Roziel on 21.07.24.
//

#include <stdbool.h>

#include "stdio.h"
#include "workerDetails.h"

void start(void)
{

    printf("Welcome to the worker management software!\n");

    int choice;
    bool option;
    option = true;

    char chosenName[32];
    while (option)
    {

        printf(" Please choose one of the following options:\n");

        printf("1. adding a worker\n");
        printf("2. deleting a worker\n");
        printf("3. editing an existing worker\n");
        printf("4. perform a query on an existing worker\n");
        printf("5. printing all worker\n");
        printf("6. quit programme");

        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            addMitarbeiter();
            break;

        case 2:
            printf("Please insert the name of the worker you want to delete:\n");
            scanf("%31s", chosenName);

            deleteMitarbeiter(chosenName);

            break;

        case 3:
            printf("Please insert the name of the worker you want to edit:\n");
            scanf("%31s", chosenName);

            editMitarbeiter(chosenName);

            break;

        case 4:

            printf("query workers\n");
            scanf("%31s", chosenName);
            queryMitarbeiter(chosenName);

            break;

        case 5:
            printf("printing all workers\n");
            printAllMitarbeiter();
            break;

        case 6:

            return;

        default:
            break;
        }
    }
}
