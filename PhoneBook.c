#include <stdio.h>
#include <stdlib.h>

#include "PhoneBook.h"
#include "Person.h"
#include "DLinkedList.h"

int SortingFunc(LData d1, LData d2) {
    return d2->idx - d1->idx ;
}

PhoneBook* CreatePhoneBook() {
    PhoneBook* pb = (PhoneBook*)malloc(sizeof(PhoneBook));
    //pb = (List*)malloc(sizeof(List));
    InitList(pb);
    SetSortRule(pb, SortingFunc);
    return pb;
}

void AddToPhoneBook(PhoneBook* pb, int idx, char* pName, char* pPhone) {
    
    LData newPerson = MakePerson(idx, pName, pPhone);
    LInsert(pb, newPerson);
}

void ListPhoneBook(PhoneBook* pb) {
    LData sdata;
    if(LFirst(pb, &sdata)) {
        ShowPersonInfo(sdata);
        while(LNext(pb, &sdata)) {
            ShowPersonInfo(sdata);
        }
    }
}

int DeleteByIDX(PhoneBook* pb, int idx) {
    LData sdata;
    int rdata;
    if(LFirst(pb, &sdata)) {
        rdata = sdata->idx;
        if(DeletePersonByIDX(sdata, idx))
            LRemove(pb);
        while(LNext(pb, &sdata)) {
            rdata = sdata->idx;
            if(DeletePersonByIDX(sdata, idx))
                LRemove(pb);
        }
    }
    return rdata;
}

char* DeleteByNAME(PhoneBook* pb, char* pName) {
    LData sdata;
    char* rdata;
    if(LFirst(pb, &sdata)) {
        rdata = sdata->szName;
        if(DeletePersonByNAME(sdata, pName))
            LRemove(pb);
        while(LNext(pb, &sdata)) {
            rdata = sdata->szName;
            if(DeletePersonByNAME(sdata, pName))
                LRemove(pb);
        }
    }
    return rdata;
}


LData UpdateByNAME(PhoneBook* pb, char* pName) {
    LData sdata;
    if(LFirst(pb, &sdata)) {
        if(UpdatePersonByNAME(sdata, pName)) 
            return sdata;
        while(LNext(pb, &sdata)) {
            if(UpdatePersonByNAME(sdata, pName))
                return sdata;
        }
    }
    return NULL;
}