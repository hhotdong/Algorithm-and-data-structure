#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphBFS.h"
#include "../../List/LinkedList/SinglyLinkedList/singly_linked_list.h"
#include "../../Queue/ArrayBaseQueue/circular_queue.h"

int WhoIsPrecede(int data1, int data2);

void GraphInit(ALGraph * pg, int nv)
{
    int i;

    pg->adjList = (List*)malloc(sizeof(List)*nv);
    pg->numV = nv;
    pg->numE = 0;

    for (int i = 0; i < nv; i++)
    {
        ListInit(&(pg->adjList[i]));
        SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
    }

    pg->visitInfo = (int *)malloc(sizeof(int) * pg->numV);
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void GraphDestroy(ALGraph * pg)
{
    if (pg->adjList != NULL)
        free(pg->adjList);

    if (pg->visitInfo != NULL)
        free(pg->visitInfo);
}

void AddEdge(ALGraph * pg, int fromV, int toV)
{
    ListInsert(&(pg->adjList[fromV]), toV);
    ListInsert(&(pg->adjList[toV]), fromV);
    pg->numE += 1;
}

void ShowGraphEdgeInfo(ALGraph * pg)
{
    int vx;
    for (int i = 0; i < pg->numV; i++)
    {
        printf("%c와 연결된 정점: ", i + 65);

        if (ListFirst(&(pg->adjList[i]), &vx))
        {
            printf("%c ", vx + 65);

            while (ListNext(&(pg->adjList[i]), &vx))
                printf("%c ", vx + 65);
        }
        printf("\n");
    }
}

int VisitVertex(ALGraph * pg, int visitV)
{
    if (pg->visitInfo[visitV] == 0)
    {
        pg->visitInfo[visitV] = 1;
        printf("%c " , visitV + 65);
        return TRUE;
    }
    return FALSE;
}

int WhoIsPrecede(int data1, int data2)
{
    if (data1 < data2)
        return 0;
    else
        return 1;
}

void BFShowGraphVertex(ALGraph * pg, int startV)
{
    Queue queue;
    int visitV = startV;
    int nextV;

    QueueInit(&queue);

    VisitVertex(pg, visitV);

    while (ListFirst(&pg->adjList[visitV], &nextV) == TRUE)
    {
        if (VisitVertex(pg, nextV) == TRUE)
            Enqueue(&queue, nextV);

        while (ListNext(&(pg->adjList[visitV]), &nextV) == TRUE)
        {
            if (VisitVertex(pg, nextV) == TRUE)
                Enqueue(&queue, nextV);
        }

        if (QueueIsEmpty(&queue) == TRUE)
            break;
        else
            visitV = Dequeue(&queue);
    }
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}
