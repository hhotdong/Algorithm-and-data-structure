// 참고: <윤성우의 열혈 자료구조>
#include <stdlib.h>
#include "list_base_stack.h"

void StackInit(Stack * pStack)
{
    pStack->head = NULL;
}

int StackIsEmpty(Stack * pStack)
{
    return pStack->head == NULL;
}

void StackPush(Stack * pStack, Data data)
{
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = pStack->head;
    pStack->head = newNode;
}

Data StackPop(Stack * pStack)
{
    if (StackIsEmpty(pStack))
        return -1;

    Node * popNode = pStack->head;
    int popData = popNode->data;
    
    pStack->head = popNode->next;
    free(popNode);
    
    return popData;
}

Data StackPeek(Stack * pStack)
{
    if (StackIsEmpty(pStack))
        return -1;

    return pStack->head->data;
}
