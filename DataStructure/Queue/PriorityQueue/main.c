#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "priority_queue.h"

int DataPriorityComp(char * str1, char * str2)
{
    return strlen(str2) - strlen(str1);
}

int main(void)
{
    PriorityQueue pq;
    PriorityQueueInit(&pq, &DataPriorityComp);

    Enqueue(&pq, "Apple");
    Enqueue(&pq, "PineApple");
    Enqueue(&pq, "WaterMelon");
    Enqueue(&pq, "Kiwi");
    Enqueue(&pq, "Orange");
    
    while (!PriorityQueueIsEmpty(&pq))
        printf("%s \n", Dequeue(&pq));

    return 0;
}
