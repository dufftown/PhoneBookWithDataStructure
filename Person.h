#ifndef __PERSON_H_
#define __PERSON_H_

#define MAX_SIZE 30

typedef struct _person {
    int idx;
    char szName[MAX_SIZE];
    char szPhone[MAX_SIZE];
} Person;

Person* MakePerson(int idx, char* pName, char* pPhone);

void ShowPersonInfo(Person* p);

void UpdataPerson(Person* p, char* pName, char* pPhone);

int DeletePersonByIDX(Person* p, int idx);

int DeletePersonByNAME(Person* p, char* pName);

int UpdatePersonByNAME(Person* p, char* pName);

#endif