// 참고: <윤성우의 열혈 자료구조>
// 힙은 완전 이진 트리이다.
// 힙의 구현은 배열을 기반으로 하며 인덱스가 0인 요소는 비워둔다.
// 따라서 힙에 저장된 노드의 개수와 마지막 노드의 고유번호 및 배열의 인덱스가 일치한다.
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
