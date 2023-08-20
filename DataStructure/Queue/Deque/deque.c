#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

void DequeInit(Deque * pDeq)
{
    pDeq->head = NULL;
    pDeq->tail = NULL;
}

int DequeIsEmpty(Deque * pDeq)
{
    if (pDeq->head == NULL)
        return TRUE;
    else
        return FALSE;
}

void DequeAddFirst(Deque * pDeq, Data data)
{
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->prev = NULL;
    newNode->next = pDeq->head;

    if (DequeIsEmpty(pDeq))
        pDeq->tail = newNode;
    else
        pDeq->head->prev = newNode;

    pDeq->head = newNode;
}

void DequeAddLast(Deque * pDeq, Data data)
{
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->prev = pDeq->tail;
    newNode->next = NULL;

    if (DequeIsEmpty(pDeq))
        pDeq->head = newNode;
    else
        pDeq->tail->next = newNode;

    pDeq->tail = newNode;
}

Data DequeRemoveFirst(Deque * pDeq)
{
    if (DequeIsEmpty(pDeq))
    {
        printf("Deque Memory Error!");
        exit(-1);
    }

    Node * delNode = pDeq->head;
    Data delData = delNode->data;

    if (delNode->next == NULL)
        pDeq->tail = NULL;
    else
        delNode->next->prev = NULL;

    pDeq->head = delNode->next;

    free(delNode);
    return delData;
}

Data DequeRemoveLast(Deque * pDeq)
{
    if (DequeIsEmpty(pDeq))
    {
        printf("Deque Memory Error!");
        exit(-1);
    }

    Node * delNode = pDeq->tail;
    Data delData = delNode->data;

    if (delNode->prev == NULL)
        pDeq->head = NULL;
    else
        delNode->prev->next = NULL;

    pDeq->tail = delNode->prev;

    free(delNode);
    return delData;
}

Data DequeGetFirst(Deque * pDeq)
{
    if (DequeIsEmpty(pDeq))
    {
        printf("Deque Memory Error!");
        exit(-1);
    }

    return pDeq->head->data;
}

Data DequeGetLast(Deque * pDeq)
{
    if (DequeIsEmpty(pDeq))
    {
        printf("Deque Memory Error!");
        exit(-1);
    }

    return pDeq->tail->data;
}
