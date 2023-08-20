// 참고: <윤성우의 열혈 자료구조>
#include <stdio.h>
#include <stdlib.h>
#include "list_base_queue.h"

void QueueInit(Queue * pq)
{
    pq->front = NULL;
    pq->rear = NULL;
}

int QueueIsEmpty(Queue * pq)
{
    if (pq->front == NULL)
        return TRUE;
    else
        return FALSE;
}

void Enqueue(Queue * pq, Data data)
{
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;

    if (QueueIsEmpty(pq))
    {
        pq->front = newNode;
        pq->rear = newNode;
    }
    else
    {
        pq->rear->next = newNode;
        pq->rear = newNode;
    }
}

Data Dequeue(Queue * pq)
{
    if (QueueIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }

    Node * dqNode = pq->front;
    int dqData = dqNode->data;
    pq->front = dqNode->next;
   
    free(dqNode);
    return dqData;
}

Data QueuePeek(Queue * pq)
{
    if (QueueIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }

    return pq->front->data;
}
