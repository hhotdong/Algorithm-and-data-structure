#include <stdlib.h>  // malloc, free
#include "circular_linked_list.h"

/*
 P   C
[D]-[0]

 P   C
[D]-[0]-[1]

     P   C
[D]-[0]-[1]

 P   C
[D]-[0]-[1]-[2]

     P   C
[D]-[0]-[1]-[2]
 
         P   C
[D]-[0]-[1]-[2]

*/

void ListInit(List * plist)
{
    plist->tail = (Node*)malloc(sizeof(Node));
    plist->tail->next = plist->tail;
    plist->cur = NULL;
    plist->prev = NULL;
    plist->numOfData = 0;
}

void ListInsert(List * plist, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->tail->next;
    plist->tail->next = newNode;
    plist->tail = newNode;

    (plist->numOfData)++;
}

void ListInsertFront(List * plist, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    newNode->next = plist->tail->next->next;
    plist->tail->next->next = newNode;
    if (newNode->next->next == newNode)
        plist->tail = newNode;

    (plist->numOfData)++;
}

int ListFirst(List * plist, Data * pdata)
{
    if (plist->tail == plist->tail->next)
        return FALSE;

    plist->prev = plist->tail->next;
    plist->cur = plist->tail->next->next;

    *pdata = plist->cur->data;
    return TRUE;
}

int ListNext(List * plist, Data * pdata)
{
    if (plist->tail == plist->tail->next)
        return FALSE;

    plist->prev = plist->cur;
    plist->cur = plist->cur->next;

    if (plist->cur == plist->tail->next)
    {
        plist->prev = plist->tail->next;
        plist->cur = plist->tail->next->next;
    }

    *pdata = plist->cur->data;
    return TRUE;
}

Data ListRemove(List * plist)
{
    Node * delNode = plist->cur;
    Data delData = delNode->data;
    
    plist->prev->next = delNode->next;
    plist->cur = plist->prev;
    
    if (delNode == plist->tail)
        plist->tail = plist->prev;
    
    free(delNode);
    (plist->numOfData)--;
    return delData;
}

int ListCount(List * plist)
{
    return plist->numOfData;
}
