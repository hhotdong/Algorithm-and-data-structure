// 참고: <윤성우의 열혈 자료구조>
#include <stdlib.h>
#include "heap.h"

void HeapInit(Heap * ph, PriorityComp * pc)
{
    ph->numOfData = 0;
    ph->comp = pc;
}

int HeapIsEmpty(Heap * ph)
{
    return ph->numOfData == 0;
}

int GetParentIdx(int idx)
{
    return idx / 2;
}

int GetLeftChildIdx(int idx)
{
    return idx * 2;
}

int GetRightChildIdx(int idx)
{
    return GetLeftChildIdx(idx) + 1;
}

int GetHighPriorityChildIdx(Heap * ph, int idx)
{
    if (GetLeftChildIdx(idx) > ph->numOfData)
        return 0;
    else if (GetLeftChildIdx(idx) == ph->numOfData)
        return GetLeftChildIdx(idx);
    else
    {
        if (ph->comp(ph->heapArr[GetLeftChildIdx(idx)], ph->heapArr[GetRightChildIdx(idx)]) < 0)
            return GetRightChildIdx(idx);
        else
            return GetLeftChildIdx(idx);
    }
}

void HeapInsert(Heap * ph, HData data)
{
    int idx = ph->numOfData + 1;

    while (idx != 1)
    {
        if (ph->comp(data, ph->heapArr[GetParentIdx(idx)]) <= 0)
            break;

        ph->heapArr[idx] = ph->heapArr[GetParentIdx(idx)];
        idx = GetParentIdx(idx);
    }

    ph->heapArr[idx] = data;
    ++(ph->numOfData);
}

HData HeapDelete(Heap * ph)
{
    HData retData = ph->heapArr[1];
    HData lastElem = ph->heapArr[ph->numOfData];

    int parentIdx = 1;
    int childIdx;

    while ((childIdx = GetHighPriorityChildIdx(ph, parentIdx)))
    {
        if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
            break;
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }

    ph->heapArr[parentIdx] = lastElem;
    --(ph->numOfData);
    return retData;
}
