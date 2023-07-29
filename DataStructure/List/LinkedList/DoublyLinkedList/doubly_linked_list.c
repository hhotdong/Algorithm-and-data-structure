#include <stdlib.h>
#include "doubly_linked_list.h"

void ListInit(List * plist)
{
    plist->head = NULL;
    plist->numOfData = 0;
}

void ListInsert(List * plist, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = NULL;

    if (plist->head == NULL)
    {
        newNode->prev = NULL;
        plist->head = newNode;
        return;
    }

    Node * cur = plist->head;
    while (cur->next != NULL)
        cur = cur->next;

    newNode->prev = cur;
    cur->next = newNode;

    ++(plist->numOfData);
}

void ListInsertFront(List * plist, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->head;
    newNode->prev = NULL;

    if (plist->head != NULL)
        plist->head->prev = newNode;
   
    plist->head = newNode;
    
    ++(plist->numOfData);
}

int ListInsertAt(List * plist, Data data, int idx)
{
    int i = 0;
    Node * cur = plist->head;

    while (cur != NULL)
    {
        if (i == idx)
        {
            Node * newNode = (Node*)malloc(sizeof(Node));
            newNode->data = data;
            
            newNode->prev = cur->prev;
            newNode->next = cur;

            if (cur->prev != NULL)
                cur->prev->next = newNode;
            cur->prev = newNode;

            ++(plist->numOfData);
            return i;
        }
        ++i;
        cur = cur->next;
    }
    
    ListInsert(plist, data);
    return i;
}

Node * ListGetAt(List * plist, int idx)
{
    int i = 0;
    Node * cur = plist->head;    
    while (cur != NULL)
    {
        if (i == idx)
            return cur;
        ++i;
        cur = cur->next;
    }
    return NULL;
}

int ListFirst(List * plist, Data * pdata)
{
    if (plist->head == NULL)
        return FALSE;

    plist->cur = plist->head;
    *pdata = plist->cur->data;
    return TRUE;
}

int ListNext(List * plist, Data * pdata)
{
    if (plist->cur->next == NULL)
        return FALSE;

    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    return TRUE;
}

int ListPrevious(List * plist, Data * pdata)
{
    if (plist->cur->prev == NULL)
        return FALSE;

    plist->cur = plist->cur->prev;
    *pdata = plist->cur->data;
    return TRUE;
}

Data ListRemove(List * plist)
{
    Node* delNode = plist->cur;
    Data delData = delNode->data;
    
    if (delNode == plist->head)
        plist->head = delNode->next;
    else
        delNode->prev->next = delNode->next;    
    
    if (delNode->next != NULL)
        delNode->next->prev = delNode->prev;

    plist->cur = delNode->prev;

    free(delNode);
    --(plist->numOfData);
    return delData;
}

int ListCount(List * plist)
{
    return plist->numOfData;
}
