// 참고: <윤성우의 열혈 자료구조>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "expression_tree.h"
#include "list_base_stack.h"

BTreeNode * MakeExpTree(char exp[])
{
    BTreeNode * newNode;
    Stack stack;
    StackInit(&stack);

    while (*exp != '\0')
    {
        newNode = MakeBTreeNode();
        
        if (isdigit(*exp))
            SetData(newNode, *exp - '0');
        else
        {
            MakeRightSubTree(newNode, StackPop(&stack));
            MakeLeftSubTree(newNode, StackPop(&stack));
            SetData(newNode, *exp);
        }
       
        StackPush(&stack, newNode);
        ++exp;
    }

    return StackPop(&stack);
}

int EvaluateExpTree(BTreeNode * bt)
{
    if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
        return GetData(bt);

    int lhs = EvaluateExpTree(GetLeftSubTree(bt));
    int rhs = EvaluateExpTree(GetRightSubTree(bt));

    switch(GetData(bt))
    {
    case '+':
        return lhs + rhs;
    
    case '-':
        return lhs - rhs;
    
    case '*':
        return lhs * rhs;
    
    case '/':
        return lhs / rhs;
    }
    
    return 0;
}

void ShowNodeData(BTData data)
{
    if (data >= 0 && data <= 9)
        printf("%d ", data);
    else
        printf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode * bt)
{
    PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode * bt)
{
    if (bt == NULL)
        return;

    if (bt->left != NULL || bt->right != NULL)
        printf(" ( ");

    ShowInfixTypeExp(bt->left);
    ShowNodeData(bt->data);
    ShowInfixTypeExp(bt->right);
    
    if (bt->left != NULL || bt->right != NULL)
        printf(" ) ");
}

void ShowPostfixTypeExp(BTreeNode * bt)
{
    PostorderTraverse(bt, ShowNodeData);
}
