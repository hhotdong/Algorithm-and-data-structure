// 참고: <윤성우의 열혈 자료구조>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "list_base_stack.h"

int GetOpPrec(char op)
{
    switch(op)
    {
    case '*':
    case '/':
        return 5;
    case '+':
    case '-':
        return 3;
    case '(':
        return 1;
    }
    return -1;
}

int WhoPrecOp(char op1, char op2)
{
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);

    if (op1Prec > op2Prec)
        return 1;
    else if (op1Prec < op2Prec)
        return -1;
    else
        return 0;
}

// RPN(=Reverse Polish Notation)
void ConvToRPNExp(char exp[])
{
    Stack stack;
    int expLen = strlen(exp);
    char * convExp = (char *)malloc(expLen+1);

    int i, idx = 0;
    char tok, popOp;

    memset(convExp, 0, sizeof(char)*expLen+1);
    StackInit(&stack);

    for (i = 0; i < expLen; i++)
    {
        tok = exp[i];

        if (isdigit(tok))
        {
            convExp[idx++] = tok;
        }
        else
        {
            switch(tok)
            {
            case '(':
                StackPush(&stack, tok);
                break;
            case ')':
                while (1)
                {
                    popOp = StackPop(&stack);
                    if (popOp == '(')
                        break;
                    convExp[idx++] = popOp;
                }
                break;
            case '+': case '-':
            case '*': case '/':
                while (!StackIsEmpty(&stack) && WhoPrecOp(StackPeek(&stack), tok) >= 0)
                    convExp[idx++] = StackPop(&stack);
                StackPush(&stack, tok);
                break;
            }
        }
    }

    while (!StackIsEmpty(&stack))
        convExp[idx++] = StackPop(&stack);

    strcpy(exp, convExp);
    free(convExp);
}
