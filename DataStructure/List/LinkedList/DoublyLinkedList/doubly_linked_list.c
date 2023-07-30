#include <stdlib.h>
#include <string.h>
#include "doubly_linked_list.h"

void ListInit(List * pList, const char * (*pfGetKey)(void *))
{
    pList->head = NULL;
    pList->numOfData = 0;
    pList->pfGetKey = pfGetKey;
}

void ListRelease(List * pList)
{
    Node * cur = pList->head;
    while (cur != NULL)
    {
        Node * delNode = cur;
        cur = cur->next;
        
        free(delNode->pData);
        free(delNode);
    }
    pList->head = NULL;
    pList->numOfData = 0;
}

void ListInsert(List * pList, void * pData)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->pData = pData;

    newNode->next = NULL;

    if (pList->head == NULL)
    {
        newNode->prev = NULL;
        pList->head = newNode;
        ++(pList->numOfData);
        return;
    }

    Node * cur = pList->head;
    while (cur->next != NULL)
        cur = cur->next;

    newNode->prev = cur;
    cur->next = newNode;

    ++(pList->numOfData);
}

void ListInsertFront(List * pList, void * pData)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->pData = pData;

    newNode->next = pList->head;
    newNode->prev = NULL;

    if (pList->head != NULL)
        pList->head->prev = newNode;
   
    pList->head = newNode;
    
    ++(pList->numOfData);
}

int ListInsertAt(List * pList, void * pData, int idx)
{
    int i = 0;
    Node * cur = pList->head;

    while (cur != NULL)
    {
        if (i == idx)
        {
            Node * newNode = (Node*)malloc(sizeof(Node));
            newNode->pData = pData;
            
            newNode->prev = cur->prev;
            newNode->next = cur;

            if (cur->prev != NULL)
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
    Node * cur = pList->head;
    while (cur != NULL)
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
    Node * cur = pList->head;    
    while (cur != NULL)
    {
        if (i == idx)
            return cur;
        ++i;
        cur = cur->next;
    }
    return NULL;
}

int ListFirst(List * pList, void ** pdata)
{
    if (pList->head == NULL)
        return FALSE;

    pList->cur = pList->head;
    *pdata = pList->cur->pData;
    return TRUE;
}

int ListNext(List * pList, void ** pData)
{
    if (pList->cur->next == NULL)
        return FALSE;

    pList->cur = pList->cur->next;
    *pData = pList->cur->pData;
    return TRUE;
}

int ListPrevious(List * pList, void ** pData)
{
    if (pList->cur->prev == NULL)
        return FALSE;

    pList->cur = pList->cur->prev;
    *pData = pList->cur->pData;
    return TRUE;
}

void * ListRemove(List * pList)
{
    Node * delNode = pList->cur;
    void * delData = delNode->pData;
    
    if (delNode == pList->head)
        pList->head = delNode->next;
    else
        delNode->prev->next = delNode->next;    
    
    if (delNode->next != NULL)
        delNode->next->prev = delNode->prev;

    pList->cur = delNode->prev;

    free(delNode);
    --(pList->numOfData);
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
