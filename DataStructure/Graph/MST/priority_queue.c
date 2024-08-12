#include <stdlib.h>
#include "priority_queue.h"

void PriorityQueueInit(PriorityQueue * ppq, PriorityComp pc)
{
    HeapInit(ppq, pc);
}

int PriorityQueueIsEmpty(PriorityQueue * ppq)
{
    return HeapIsEmpty(ppq);
}

void Enqueue(PriorityQueue * ppq, PriorityQueueData data)
{
    HeapInsert(ppq, data);
}

PriorityQueueData Dequeue(PriorityQueue * ppq)
{
    return HeapDelete(ppq);
}
