#include "deque_base_queue.h"
#include "deque.h"

void QueueInit(Queue * pq)
{
    DequeInit(pq);
}

int QueueIsEmpty(Queue * pq)
{
    return DequeIsEmpty(pq);
}

void Enqueue(Queue * pq, Data data)
{
    DequeAddLast(pq, data);
}

Data Dequeue(Queue * pq)
{
    return DequeRemoveFirst(pq);
}

Data QueuePeek(Queue * pq)
{
    return DequeGetFirst(pq);
}
