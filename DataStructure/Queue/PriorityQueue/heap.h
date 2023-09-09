// 참고: <윤성우의 열혈 자료구조>
#ifndef _HEAP_H_
#define _HEAP_H_

#define TRUE  1
#define FALSE 0

#define HEAP_LEN 100

typedef char * HData;
typedef int PriorityComp(HData d1, HData d2);

typedef struct _heap
{
    PriorityComp * comp;
    int numOfData;
    HData heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap * ph, PriorityComp * pc);
int HeapIsEmpty(Heap * ph);

void HeapInsert(Heap * ph, HData data);
HData HeapDelete(Heap * ph);

#endif  // _HEAP_H_
