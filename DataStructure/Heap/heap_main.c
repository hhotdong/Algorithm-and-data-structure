#include <stdio.h>
#include "heap.h"

int DataPriorityComp(char ch1, char ch2)
{
    return ch2 - ch1;
}

int main(void)
{
    Heap heap;
    HeapInit(&heap, &DataPriorityComp);

    HeapInsert(&heap, 'A');
    HeapInsert(&heap, 'B');
    HeapInsert(&heap, 'C');
    printf("%c \n", HeapDelete(&heap));

    HeapInsert(&heap, 'A');
    HeapInsert(&heap, 'B');
    HeapInsert(&heap, 'C');
    printf("%c \n", HeapDelete(&heap));
    
    while (!HeapIsEmpty(&heap))
        printf("%c \n", HeapDelete(&heap));
    
    return 0;
}
