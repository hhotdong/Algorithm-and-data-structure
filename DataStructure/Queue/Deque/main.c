#include <stdio.h>
#include "deque.h"

int main(void)
{
    Deque deq;
    DequeInit(&deq);

    DequeAddFirst(&deq, 3);
    DequeAddFirst(&deq, 2);
    DequeAddFirst(&deq, 1);

    DequeAddLast(&deq, 4);
    DequeAddLast(&deq, 5);
    DequeAddLast(&deq, 6);

    while (!DequeIsEmpty(&deq))
        printf("%d ", DequeRemoveFirst(&deq));

    printf("\n");

    DequeAddFirst(&deq, 3);
    DequeAddFirst(&deq, 2);
    DequeAddFirst(&deq, 1);

    DequeAddLast(&deq, 4);
    DequeAddLast(&deq, 5);
    DequeAddLast(&deq, 6);

    while (!DequeIsEmpty(&deq))
        printf("%d ", DequeRemoveLast(&deq));

    return 0;
}
