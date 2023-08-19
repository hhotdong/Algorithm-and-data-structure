// 참고: <윤성우의 열혈 자료구조>
#ifndef _AB_STACK_H_
#define _AB_STACK_H_

#define TRUE      1
#define FALSE     0
#define STACK_LEN 100

typedef int Data;

typedef struct _arrayStack
{
    Data stackArr[STACK_LEN];
    int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack * pStack);
int StackIsEmpty(Stack * pStack);
void StackPush(Stack * pStack, Data data);
Data StackPop(Stack * pStack);
Data StackPeek(Stack * pStack);

#endif  // _AB_STACK_H_
