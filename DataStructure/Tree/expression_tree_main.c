// 참고: <윤성우의 열혈 자료구조>
#include <stdio.h>
#include "expression_tree.h"

int main(void)
{
    BTreeNode * expTree = MakeExpTree("12+7*");

    printf("전위 표기법의 수식: ");
    ShowPrefixTypeExp(expTree); printf("\n");
    
    printf("중위 표기법의 수식: ");
    ShowInfixTypeExp(expTree); printf("\n");
    
    printf("후위 표기법의 수식: ");
    ShowPostfixTypeExp(expTree); printf("\n");
    
    printf("연산의 결과: %d \n", EvaluateExpTree(expTree));

    return 0;
}
