#ifndef _DEQUE_H_
#define _DEQUE_H_

#define TRUE  1
#define FALSE 0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node * next;
    struct _node * prev;
} Node;

typedef struct _doulbyLinkedDeque
{
    Node * head;
    Node * tail;
} DoublyLinkedDeque;

typedef DoublyLinkedDeque Deque;

void DequeInit(Deque * pDeq);
int DequeIsEmpty(Deque * pDeq);
void DequeAddFirst(Deque * pDeq, Data data);
void DequeAddLast(Deque * pDeq, Data data);
Data DequeRemoveFirst(Deque * pDeq);
Data DequeRemoveLast(Deque * pDeq);
Data DequeGetFirst(Deque * pDeq);
Data DequeGetLast(Deque * pDeq);

#endif
