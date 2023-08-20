// 참고: <윤성우의 열혈 자료구조>
#include <string.h>
#include <stdlib.h>
#include "infix_to_postfix.h"  // ConvToRPNExp
#include "post_calculator.h"   // EvalRPNExp

int EvalInfixExp(char exp[])
{
    int len = strlen(exp);
    int ret;
    char * expcpy = (char *)malloc(len+1);
    strcpy(expcpy, exp);

    ConvToRPNExp(expcpy);
    ret = EvalRPNExp(expcpy);

    free(expcpy);
    return ret;
}

