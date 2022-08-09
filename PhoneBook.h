#ifndef __PHONEBOOK_H_
#define __PHONEBOOK_H_

#include "DLinkedList.h"
#include "Person.h"


typedef List PhoneBook;


PhoneBook* CreatePhoneBook();

void AddToPhoneBook(PhoneBook* pb, int idx, char* pName, char* pPhone);

void ListPhoneBook(PhoneBook* pb);

//void UpdataPhoneBook();

int DeleteByIDX(PhoneBook* pb, int idx);

char* DeleteByNAME(PhoneBook* pb, char* pName);

LData UpdateByNAME(PhoneBook* pb, char* pName);

#endif