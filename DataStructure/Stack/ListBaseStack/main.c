#include <stdio.h>
#include "list_base_stack.h"

int main(void)
{
    Stack stack;
    StackInit(&stack);

    StackPush(&stack, 1); StackPush(&stack, 2);
    StackPush(&stack, 3); StackPush(&stack, 4);
    StackPush(&stack, 5);
    
    while (!StackIsEmpty(&stack))
        printf("%d ", StackPop(&stack));

    return 0;
}
