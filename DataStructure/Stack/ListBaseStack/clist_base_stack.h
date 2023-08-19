// 참고: <윤성우의 열혈 자료구조>
#ifndef _CLB_STACK_H_
#define _CLB_STACK_H_

#include "circular_linked_list.h"

typedef struct _listStack
{
    List * list;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack * pStack);
int StackIsEmpty(Stack * pStack);
void StackPush(Stack * pStack, Data data);
Data StackPop(Stack * pStack);
Data StackPeek(Stack * pStack);

#endif  // _CLB_STACK_H_
