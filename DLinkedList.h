#ifndef __D_LINKED_LIST_H_
#define __D_LINKED_LIST_H_

#define TRUE 1
#define FALSE 0

#include "Person.h"

typedef Person* LData;

typedef int (*SortFunc)(LData d1, LData d2);

typedef struct _dl_node {
    LData data;
    struct _dl_node * next;
} Node;

typedef struct _d_linked_list {
    Node* head;
    Node* cur;
    Node* before;

    int numOfData;
    SortFunc func;
} DLinkedList;

typedef DLinkedList List;

void InitList(List* pList);

void SetSortRule(List* pList, SortFunc func);

int LCount(List* pList);

int LFirst(List* pList, LData* pData);

int LNext(List* pList, LData* pData);

void LInsert(List* pList, LData data);

LData LRemove(List* pList);

#endif