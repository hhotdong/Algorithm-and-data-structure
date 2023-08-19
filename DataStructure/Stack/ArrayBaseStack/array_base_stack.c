// 참고: <윤성우의 열혈 자료구조>
#include "array_base_stack.h"

void StackInit(Stack * pStack)
{
    pStack->topIndex = -1;
}

int StackIsEmpty(Stack * pStack)
{
    return pStack->topIndex == -1;
}

void StackPush(Stack * pStack, Data data)
{
    pStack->stackArr[++pStack->topIndex] = data;
}

Data StackPop(Stack * pStack)
{
    return pStack->stackArr[pStack->topIndex--];
}

Data StackPeek(Stack *pStack)
{
    return pStack->stackArr[pStack->topIndex];
}
