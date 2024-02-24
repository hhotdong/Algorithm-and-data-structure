// 참고: <윤성우의 열혈 자료구조>
#ifndef _LB_STACK_H_
#define _LB_STACK_H_

#include "binary_tree.h"

#define TRUE  1
#define FALSE 0

typedef BTreeNode * Data;

typedef struct _node
{
    Data data;
    struct _node * next;
} Node;

typedef struct _listStack
{
    Node * head;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack * pStack);
int StackIsEmpty(Stack * pStack);
void StackPush(Stack * pStack, Data data);
Data StackPop(Stack * pStack);
Data StackPeek(Stack * pStack);

#endif  // _LB_STACK_H_
