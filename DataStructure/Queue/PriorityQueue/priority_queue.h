#include "heap.h"

typedef Heap PriorityQueue;
typedef HData PriorityQueueData;

void PriorityQueueInit(PriorityQueue * ppq, PriorityComp pc);
int PriorityQueueIsEmpty(PriorityQueue * ppq);

void Enqueue(PriorityQueue * ppq, PriorityQueueData data);
PriorityQueueData Dequeue(PriorityQueue * ppq);
