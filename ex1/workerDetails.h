//
// Created by Michal Roziel on 18.07.24.
//

#ifndef WORKERDETAILS_H
#define WORKERDETAILS_H

typedef struct {
    char name[32];
    int age;
    char branch[32];
    float salary;
} worker;

void addMitarbeiter();
void deleteMitarbeiter(char* name);
void editMitarbeiter(char* name);
void queryMitarbeiter(char* name);
void printAllMitarbeiter();

#endif //WORKERDETAILS_H
