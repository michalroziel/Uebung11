//
// Created by Michal Roziel on 18.07.24.
//
#include <stdio.h>
#include  "workerDetails.h"

worker mitarbeiter[50];

void addMitarbeiter() {
    printf("Welcome to the add worker menu!\n");

    char name[32];
    printf("Please enter the worker's name: ");
    scanf("%s", name); // use %31s to limit input length and avoid buffer overflow
    printf("the new workers name is : %s\n", name);
}

