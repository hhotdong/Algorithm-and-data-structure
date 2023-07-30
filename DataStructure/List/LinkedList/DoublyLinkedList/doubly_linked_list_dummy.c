#include <stdlib.h>
#include <string.h>
#include "doubly_linked_list.h"

void ListInit(List * pList, const char * (*pfGetKey)(void *))
{
    pList->head = (Node*)malloc(sizeof(Node));
    pList->tail = (Node*)malloc(sizeof(Node));

    pList->head->next = pList->tail;
    pList->head->prev = NULL;

    pList->tail->next = NULL;
    pList->tail->prev = pList->head;

    pList->numOfData = 0;
    pList->pfGetKey = pfGetKey;
}

void ListRelease(List * pList)
{
    Node * cur = pList->head->next;
    while (cur != pList->tail)
    {
        Node * delNode = cur;
        cur = cur->next;
        
        free(delNode->pData);
        free(delNode);
    }
    pList->head->next = pList->tail;
    pList->tail->prev = pList->head;
    pList->cur = NULL;
    pList->pfGetKey = NULL;
    pList->numOfData = 0;
}

void ListInsert(List * pList, void * pData)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->pData = pData;
    
    newNode->prev = pList->tail->prev;
    newNode->next = pList->tail;

    pList->tail->prev->next = newNode;
    pList->tail->prev = newNode;
    
    ++(pList->numOfData);
}

void ListInsertFront(List * pList, void* pData)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->pData = pData;

    newNode->prev = pList->head;
    newNode->next = pList->head->next;

    pList->head->next->prev = newNode;
    pList->head->next = newNode;

    ++(pList->numOfData);
}

int ListInsertAt(List * pList, void * pData, int idx)
{
    int i = 0;
    Node * cur = pList->head->next;
    while (cur != pList->tail)
    {
        if (i == idx)
        {
            Node * newNode = (Node*)malloc(sizeof(Node));
            newNode->pData = pData;
            
            newNode->prev = cur->prev;
            newNode->next = cur;

            cur->prev->next = newNode;
            cur->prev = newNode;

            ++(pList->numOfData);
            return i;
        }
        ++i;
        cur = cur->next;
    }
    
    ListInsert(pList, pData);
    return i;
}

Node * ListFindNode(List * pList, const char * pKey)
{
    Node * cur = pList->head->next;
    while (cur != pList->tail)
    {
        if (strcmp(pList->pfGetKey(cur->pData), pKey) == 0)
            return cur;
        cur = cur->next;
    }
    return NULL;
}

Node * ListGetAt(List * pList, int idx)
{
    int i = 0;
    Node * cur = pList->head->next;
    while (cur != pList->tail)
    {
        if (i == idx)
            return cur;
        ++i;
        cur = cur->next;
    }
    return NULL;
}

int ListFirst(List * pList, void ** pData)
{
   if (pList->head->next == pList->tail)
       return FALSE;

   pList->cur = pList->head->next;
   *pData = pList->cur->pData;
   return TRUE;
}

int ListNext(List * pList, void ** pData)
{
    if (pList->cur->next == pList->tail)
        return FALSE;

    pList->cur = pList->cur->next;
    *pData = pList->cur->pData;
    return TRUE;
}

int ListPrevious(List * pList, void ** pData)
{
    if (pList->cur->prev == pList->head)
        return FALSE;
    
    pList->cur = pList->cur->prev;
    *pData = pList->cur->pData;
    return TRUE;
}

void * ListRemove(List * pList)
{
    Node * delNode = pList->cur;
    void * delData = delNode->pData;

    delNode->next->prev = delNode->prev;
    delNode->prev->next = delNode->next;

    pList->cur = pList->cur->prev;

    free(delNode);
    (pList->numOfData)--;
    return delData;
}

int ListRemoveNode(List * pList, const char * pKey)
{
    int i = 0;
    void * pData = NULL;

    if (ListFirst(pList, &pData))
    {
        if (strcmp(pList->pfGetKey(pList->cur->pData), pKey) == 0)
        {
            free(ListRemove(pList));
            return i;
        }
        
        while (ListNext(pList, &pData))
        {
            ++i;
            if (strcmp(pList->pfGetKey(pList->cur->pData), pKey) == 0)
            {
                free(ListRemove(pList));
                return i;
            }
        }
    }
    return -1;
}

int ListCount(List * pList)
{
    return pList->numOfData;
}
