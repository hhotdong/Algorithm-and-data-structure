// 윤성우의 <열혈 자료구조>
#include <stdio.h>
#include <stdlib.h>
#include "ALGraph.h"
#include "../../List/LinkedList/SinglyLinkedList/singly_linked_list.h"

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
}

void GraphDestroy(ALGraph * pg)
{
    if (pg->adjList != NULL)
        free(pg->adjList);
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

int WhoIsPrecede(int data1, int data2)
{
    if (data1 < data2)
        return 0;
    else
        return 1;
}
