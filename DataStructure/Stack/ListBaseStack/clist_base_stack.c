// 참고: <윤성우의 열혈 자료구조>
#include <stdlib.h>
#include "clist_base_stack.h"
#include "circular_linked_list.h"

void StackInit(Stack * pStack)
{
    pStack->list = (List *)malloc(sizeof(List));
    ListInit(pStack->list);
}

int StackIsEmpty(Stack * pStack)
{
    return ListCount(pStack->list) == 0;
}

void StackPush(Stack * pStack, Data data)
{
    ListInsertFront(pStack->list, data);
}

Data StackPop(Stack * pStack)
{
    Data popData;
    ListFirst(pStack->list, &popData);
    ListRemove(pStack->list);
    return popData;
}

Data StackPeek(Stack * pStack)
{
    Data peekData;
    ListFirst(pStack->list, &peekData);
    return peekData;
}
