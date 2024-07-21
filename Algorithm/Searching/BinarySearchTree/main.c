#include <stdio.h>
#include "binary_search_tree.h"

void SearchNode(BTreeNode * pRoot, BSTData data)
{
    BTreeNode * searchNode = BSTSearch(pRoot, data);
    if (searchNode == NULL)
        printf("탐색 실패 \n");
    else
        printf("탐색 성공: %d \n", BSTGetNodeData(searchNode));
}

int main(void)
{
    BTreeNode * bstRoot;
    BSTMakeAndInit(&bstRoot);

    BSTInsert(&bstRoot, 9);
    BSTInsert(&bstRoot, 1);
    BSTInsert(&bstRoot, 6);
    BSTInsert(&bstRoot, 2);
    BSTInsert(&bstRoot, 8);
    BSTInsert(&bstRoot, 3);
    BSTInsert(&bstRoot, 5);

    SearchNode(bstRoot, 1);
    SearchNode(bstRoot, 4);
    SearchNode(bstRoot, 6);
    SearchNode(bstRoot, 7);

    return 0;
}
