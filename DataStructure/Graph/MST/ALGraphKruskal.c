#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphKruskal.h"
#include "ALEdge.h"
#include "singly_linked_list.h"
#include "array_base_stack.h"

int WhoIsPrecede();
int PQWeightComp(Edge d1, Edge d2);
int VisitVertex(ALGraph * pg, int visitV);
void RemoveEdge(ALGraph * pg, int fromV, int toV);
void RemoveWayEdge(ALGraph * pg, int fromV, int toV);
void RecoverEdge(ALGraph * pg, int fromV, int toV, int weight);
int IsConnVertex(ALGraph * pg, int v1, int v2);

void GraphInit(ALGraph * pg, int nv)
{
    pg->adjList = (List*)malloc(sizeof(List) * nv);
    pg->numV = nv;
    pg->numE = 0;

    for (int i = 0; i < nv; i++)
    {
        ListInit(&(pg->adjList[i]));
        SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
    }

    pg->visitInfo = (int *)malloc(sizeof(int) * pg->numV);
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);

    PriorityQueueInit(&(pg->pqueue), PQWeightComp);
}

void GraphDestroy(ALGraph * pg)
{
    if (pg->adjList != NULL)
        free(pg->adjList);

    if (pg->visitInfo != NULL)
        free(pg->visitInfo);
}

void AddEdge(ALGraph * pg,  int fromV, int toV, int weight)
{
    Edge edge = { fromV, toV, weight };

    ListInsert(&(pg->adjList[fromV]), toV);
    ListInsert(&(pg->adjList[toV]), fromV);
    pg->numE += 1;

    Enqueue(&(pg->pqueue), edge);
}

void ConKruskalMST(ALGraph * pg)
{
    Edge recvEdge[20];
    Edge edge;
    int eidx = 0;

    while (pg->numE + 1 > pg->numV)  // (MST 간선의 수 + 1) == (정점의 수)
    {
        edge = Dequeue(&(pg->pqueue));
        RemoveEdge(pg, edge.v1, edge.v2);

        if (!IsConnVertex(pg, edge.v1, edge.v2))
        {
            RecoverEdge(pg, edge.v1, edge.v2, edge.weight);
            recvEdge[eidx++] = edge;
        }
    }

    for (int i = 0; i < eidx; i++)
        Enqueue(&(pg->pqueue), recvEdge[i]);
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

void ShowGraphEdgeWeightInfo(ALGraph * pg)
{
    PriorityQueue copyPQ = pg->pqueue;
    Edge edge;

    while (!PriorityQueueIsEmpty(&copyPQ))
    {
        edge = Dequeue(&copyPQ);
        printf("(%c-%c), w:%d \n", edge.v1+65, edge.v2+65, edge.weight);
    }
}

int IsConnVertex(ALGraph * pg, int v1, int v2)
{
    Stack stack;
    int visitV = v1;
    int nextV;

    StackInit(&stack);
    VisitVertex(pg, visitV);
    StackPush(&stack, visitV);

    while (ListFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
    {
        int visitFlag = FALSE;

        if (nextV == v2)
        {
            memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
            return TRUE;
        }

        if (VisitVertex(pg, nextV) == TRUE)
        {
            StackPush(&stack, visitV);
            visitV = nextV;
            visitFlag = TRUE;
        }
        else
        {
            while (ListNext(&(pg->adjList[visitV]), &nextV) == TRUE)
            {
                if (nextV == v2)
                {
                    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
                    return TRUE;
                }

                if (VisitVertex(pg, nextV) == TRUE)
                {
                    StackPush(&stack, visitV);
                    visitV = nextV;
                    visitFlag = TRUE;
                    break;
                }
            }
        }

        if (visitFlag == FALSE)
        {
            if (StackIsEmpty(&stack) == TRUE)
                break;
            else
                visitV = StackPop(&stack);
        }
    }
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
    return FALSE;
}

int VisitVertex(ALGraph * pg, int visitV)
{
    if (pg->visitInfo[visitV] == 0)
    {
        pg->visitInfo[visitV] = 1;
        return TRUE;
    }
    return FALSE;
}

int PQWeightComp(Edge d1, Edge d2)
{
    return d1.weight - d2.weight;
}

void RemoveEdge(ALGraph * pg, int fromV, int toV)
{
    RemoveWayEdge(pg, fromV, toV);
    RemoveWayEdge(pg, toV, fromV);
    (pg->numE)--;
}

void RemoveWayEdge(ALGraph * pg, int fromV, int toV)
{
    int edge;

    if (ListFirst(&(pg->adjList[fromV]), &edge))
    {
        if (edge == toV)
        {
            ListRemove(&(pg->adjList[fromV]));
            return;
        }

        while (ListNext(&(pg->adjList[fromV]), &edge))
        {
            if (edge == toV)
            {
                ListRemove(&(pg->adjList[fromV]));
                return;
            }
        }
    }
}

void RecoverEdge(ALGraph * pg, int fromV, int toV, int weight)
{
    ListInsert(&(pg->adjList[fromV]), toV);
    ListInsert(&(pg->adjList[toV]), fromV);
    (pg->numE)++;
}

int WhoIsPrecede(int data1, int data2)
{
    if (data1 < data2)
        return 0;
    else
        return 1;
}
