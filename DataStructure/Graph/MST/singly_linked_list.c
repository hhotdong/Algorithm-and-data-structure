#include <stdio.h>
#include <stdlib.h>  // malloc, free
#include "singly_linked_list.h"

void ListInit(List * plist)
{
    plist->head = (Node*)malloc(sizeof(Node));  // Dummy node
    plist->head->next = NULL;
    plist->comp = NULL;
    plist->numOfData = 0;
}

void FInsert(List * plist, LData data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = plist->head->next;
    plist->head->next = newNode;
    (plist->numOfData)++;
}

void SInsert(List * plist, LData data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    Node * prev = plist->head;
    while (prev->next != NULL && plist->comp(data, prev->next->data))
        prev = prev->next;

    newNode->next = prev->next;
    prev->next = newNode;
    (plist->numOfData)++;
    
}

void ListInsert(List * plist, LData data)
{
    if (plist->comp == NULL)
        FInsert(plist, data);
    else
        SInsert(plist, data);
}

int ListFirst(List * plist, LData * pdata)
{
    if (plist->head->next == NULL)
        return FALSE;
    
    plist->prev = plist->head;
    plist->cur = plist->head->next;
    *pdata = plist->cur->data;
    return TRUE;
}

int ListNext(List * plist, LData * pdata)
{
    if (plist->cur->next == NULL)
        return FALSE;
    
    plist->prev = plist->cur;
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    return TRUE;
}

LData ListRemove(List * plist)
{
    Node * delNode = plist->cur;
    LData delData = delNode->data;
    plist->prev->next = delNode->next;
    plist->cur = plist->prev;  // Make sure plist->cur points to the most recently accessed node
    free(delNode);
    (plist->numOfData)--;
    return delData;
}

int ListCount(List * plist)
{
    return plist->numOfData;
}

int ListIsEmpty(List * plist)
{
    return plist->numOfData < 1;
}

void SetSortRule(List * plist, int (*comp)(LData, LData))
{
    plist->comp = comp;
}
