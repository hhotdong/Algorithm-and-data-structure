// 참고: <윤성우의 열혈 자료구조>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "list_base_stack.h"

int EvalRPNExp(char exp[])
{
    Stack stack;
    int expLen = strlen(exp);
    int i;
    char tok, op1, op2;

    StackInit(&stack);
    
    for (i = 0; i < expLen; ++i)
    {
        tok = exp[i];
        if (isdigit(tok))
        {
            StackPush(&stack, tok - '0');
        }
        else
        {
            op2 = StackPop(&stack);
            op1 = StackPop(&stack);

            switch (tok)
            {
            case '+': 
                StackPush(&stack, op1+op2);
                break;
            case '-':
                StackPush(&stack, op1-op2);
                break;
            case '*': 
                StackPush(&stack, op1*op2);
                break;
            case '/':
                StackPush(&stack, op1/op2);
                break;
            }
        }
    }
    return StackPop(&stack);
}
