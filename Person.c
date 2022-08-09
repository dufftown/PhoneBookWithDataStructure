#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DLinkedList.h"
#include "Person.h"

Person* MakePerson(int idx, char* pName, char* pPhone) {
    Person* newPerson = (Person*)malloc(sizeof(Person));
    newPerson->idx = idx;
    strcpy(newPerson->szName, pName);
    strcpy(newPerson->szPhone, pPhone);
    return newPerson;
}

void ShowPersonInfo(Person* p) {
    printf("%d. %s (%s)\n", p->idx, p->szName, p->szPhone);
}

int DeletePersonByIDX(Person* p, int idx) {
    int rdata = p->idx;

    if(p->idx == idx) {
        free(p);
        return TRUE;
    }
    return FALSE;
}

int DeletePersonByNAME(Person* p, char* pName) {

    if(strcmp(p->szName,pName) == 0) {
        free(p);
        return TRUE;
    }
    return FALSE;
}

int UpdatePersonByNAME(Person* p, char* pName) {
    if(strcmp(p->szName, pName) == 0) {
        return TRUE;
    }
    return FALSE;
}
