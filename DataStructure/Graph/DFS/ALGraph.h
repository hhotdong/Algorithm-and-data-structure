// 윤성우의 <열혈 자료구조>
#ifndef __AL_GRAPH__
#define __AL_GRAPH__

#include "../../List/LinkedList/SinglyLinkedList/singly_linked_list.h"

enum { A, B, C, D, E, F, G, H, I, J };

typedef struct _ual
{
    int numV;
    int numE;
    List * adjList;
} ALGraph;

void GraphInit(ALGraph * pg, int nv);
void GraphDestroy(ALGraph * pg);
void AddEdge(ALGraph * pg, int fromV, int toV);
void ShowGraphEdgeInfo(ALGraph * pg);

#endif  // __AL_GRAPH__
