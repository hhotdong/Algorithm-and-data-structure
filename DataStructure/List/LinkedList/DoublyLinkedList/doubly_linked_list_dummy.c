#include <stdlib.h>
#include "doubly_linked_list.h"

void ListInit(List * plist)
{
    plist->head = (Node*)malloc(sizeof(Node));
    plist->tail = (Node*)malloc(sizeof(Node));

    plist->head->next = plist->tail;
    plist->head->prev = NULL;

    plist->tail->next = NULL;
    plist->tail->prev = plist->head;

    plist->numOfData = 0;
}

void ListInsert(List * plist, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    newNode->prev = plist->tail->prev;
    newNode->next = plist->tail;

    plist->tail->prev->next = newNode;
    plist->tail->prev = newNode;
    
    (plist->numOfData)++;
}

int ListFirst(List * plist, Data * pdata)
{
   if (plist->head->next == plist->tail)
       return FALSE;

   plist->cur = plist->head->next;
   *pdata = plist->cur->data;
   return TRUE;
}

int ListNext(List * plist, Data * pdata)
{
    if (plist->cur->next == plist->tail)
        return FALSE;

    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    return TRUE;
}

int ListPrevious(List * plist, Data * pdata)
{
    if (plist->cur->prev == plist->head)
        return FALSE;
    
    plist->cur = plist->cur->prev;
    *pdata = plist->cur->data;
    return TRUE;
}

Data ListRemove(List * plist)
{
    Node * delNode = plist->cur;
    Data delData = delNode->data;

    delNode->next->prev = delNode->prev;
    delNode->prev->next = delNode->next;

    plist->cur = plist->cur->prev;

    free(delNode);
    (plist->numOfData)--;
    return delData;
}

int ListCount(List * plist)
{
    return plist->numOfData;
}
