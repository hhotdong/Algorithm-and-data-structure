// 참고: <윤성우의 열혈 자료구조>
#include <stdlib.h>
#include <stdio.h>
#include "circular_queue.h"

void QueueInit(Queue * pq)
{
    pq->front = 0;
    pq->rear = 0;
}

int QueueIsEmpty(Queue * pq)
{
    if (pq->front == pq->rear)
        return TRUE;
    else
        return FALSE;
}

int NextPosIdx(int pos)
{
    if (pos == QUE_LEN - 1)
        return 0;
    else
        return pos + 1;
}

void Enqueue(Queue * pq, Data data)
{
    if (NextPosIdx(pq->rear) == pq->front)
    {
        printf("Queue Memory Error!");
        exit(-1);
    }

    pq->rear = NextPosIdx(pq->rear);
    pq->queArr[pq->rear] = data;
}

Data Dequeue(Queue * pq)
{
    if (QueueIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }

    pq->front = NextPosIdx(pq->front);
    return pq->queArr[pq->front];
}

Data QueuePeek(Queue * pq)
{
    if (QueueIsEmpty(pq))
        return -1;

    return pq->queArr[NextPosIdx(pq->front)];
}
