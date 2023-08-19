#include <stdlib.h>  // malloc, free
#include "circular_linked_list.h"

void ListInit(List * plist)
{
    plist->tail = NULL;
    plist->cur = NULL;
    plist->prev = NULL;
    plist->numOfData = 0;
}

void ListInsert(List * plist, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (plist->tail == NULL)
    {
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
        plist->tail = newNode;
    }
    (plist->numOfData)++;
}

void ListInsertFront(List * plist, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (plist->tail == NULL)
    {
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
    }

    (plist->numOfData)++;
}

int ListFirst(List * plist, Data * pdata)
{
    if (plist->tail == NULL)
        return FALSE;

    plist->prev = plist->tail;
    plist->cur = plist->tail->next;

    *pdata = plist->cur->data;
    return TRUE;
}

int ListNext(List * plist, Data * pdata)
{
    if (plist->tail == NULL)
        return FALSE;

    plist->prev = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE;
}

Data ListRemove(List * plist)
{
    Node * delNode = plist->cur;
    Data delData = delNode->data;

    if (delNode == plist->tail)
    {
        if (delNode == delNode->next)
            plist->tail = NULL;
        else
            plist->tail = plist->prev;
    }

    plist->prev->next = delNode->next;
    plist->cur = plist->prev;
    free(delNode);
    (plist->numOfData)--;
    return delData;
}

int ListCount(List * plist)
{
    return plist->numOfData;
}
