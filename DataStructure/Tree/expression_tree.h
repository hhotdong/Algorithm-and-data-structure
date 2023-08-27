// 참고: <윤성우의 열혈 자료구조>
#ifndef _EXPRESSION_TREE_H_
#define _EXPRESSION_TREE_H_

#include "binary_tree.h"

BTreeNode * MakeExpTree(char exp[]);
int EvaluateExpTree(BTreeNode * bt);

void ShowPrefixTypeExp(BTreeNode * bt);
void ShowInfixTypeExp(BTreeNode * bt);
void ShowPostfixTypeExp(BTreeNode * bt);

#endif  // _EXPRESSION_TREE_H_
