// 참고: <윤성우의 열혈 자료구조>
#ifndef _LIST_BASE_QUEUE_H_
#define _LIST_BASE_QUEUE_H_

#define TRUE  1
#define FALSE 0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node * next;
} Node;

typedef struct _listQueue
{
    Node * front;
    Node * rear;
} ListQueue;

typedef ListQueue Queue;

void QueueInit(Queue * pq);
int QueueIsEmpty(Queue * pq);
void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QueuePeek(Queue * pq);

#endif  // _LIST_BASE_QUEUE_H_
