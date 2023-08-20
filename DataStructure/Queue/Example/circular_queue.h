// 참고: <윤성우의 열혈 자료구조>
#ifndef _C_QUEUE_H_
#define _C_QUEUE_H_

#define TRUE  1
#define FALSE 0

#define QUE_LEN 100
typedef int Data;

typedef struct _circularQueue
{
    int front;
    int rear;
    Data queArr[QUE_LEN];
} CircularQueue;

typedef CircularQueue Queue;

void QueueInit(Queue * pq);
int QueueIsEmpty(Queue * pq);
void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QueuePeek(Queue * pq);

#endif  // _C_QUEUE_H_
