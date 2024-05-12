// 윤성우의 열혈 자료구조
#include <iostream>
#include "../../../DataStructure/Heap/heap.h"

int PriComp(int n1, int n2)
{
    return n2 - n1;
}

void HeapSort(int arr[], int n, PriorityComp pc)
{
    Heap heap;
    int i;
    HeapInit(&heap, pc);

    for (i = 0; i < n; i++)
        HeapInsert(&heap, arr[i]);

    for (i = 0; i < n; i++)
        arr[i] = HeapDelete(&heap);
}

int main(void)
{
    int arr[4] = { 3, 4, 2, 1 };
    int i;

    HeapSort(arr, sizeof(arr) / sizeof(int), PriComp);

    for (i = 0; i < 4; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}
