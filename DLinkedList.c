#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void InitList(List* pList) {
    pList->head = (Node*)malloc(sizeof(Node));
    pList->head->next = NULL;

    pList->cur = NULL;
    pList->before = NULL;
    pList->numOfData = 0;
    pList->func = NULL;
}

int LCount(List* pList) {
    return pList->numOfData;
}

void SetSortRule(List* pList, SortFunc func) {
    pList->func = func;
}

void SInsert(List* pList, LData data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    Node* prior = pList->head;

    while(prior->next != NULL && pList->func(prior->next->data, data) > 0) {
        prior = prior->next;
    }
    newNode->next = prior->next;
    prior->next = newNode;
    (pList->numOfData)++;
}

void FInsert(List* pList, LData data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = pList->head->next;
    pList->head->next = newNode;

    (pList->numOfData)++;
}

void LInsert(List* pList, LData data) {
    if(pList->func == NULL) {
        FInsert(pList, data);
    } else {
        SInsert(pList, data);
    }
}

int LFirst(List* pList, LData* pData) {
    if(pList->head->next == NULL) 
        return FALSE;
    pList->before = pList->head;
    pList->cur = pList->head->next;
    *pData = pList->cur->data;
    return TRUE;
}

int LNext(List* pList, LData* pData) {
    if(pList->cur->next == NULL) {
        return FALSE;
    }
    pList->before = pList->cur;
    pList->cur = pList->cur->next;
    *pData = pList->cur->data;
    return TRUE;
}

LData LRemove(List* pList) {
    Node* delNode = pList->cur;
    LData rdata = delNode->data;

    pList->before->next = pList->cur->next;
    pList->cur = pList->before;

    free(delNode);
    (pList->numOfData)--;
    return rdata;
}

