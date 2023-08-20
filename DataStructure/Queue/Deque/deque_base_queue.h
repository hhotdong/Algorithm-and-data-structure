#ifndef _DEQUE_BASE_QUEUE_H_
#define _DEQUE_BASE_QUEUE_H_

#include "deque.h"

typedef Deque Queue;

void QueueInit(Queue * pq);
int QueueIsEmpty(Queue * pq);
void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QueuePeek(Queue * pq);

#endif  // _DEQUE_BASE_QUEUE_H_
