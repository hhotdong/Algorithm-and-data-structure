#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

void SearchNode(BTreeNode * pRoot, BSTData data)
{
    BTreeNode * searchNode = BSTSearch(pRoot, data);
    if (searchNode == NULL)
        printf("탐색 실패 \n");
    else
        printf("탐색 성공: %d \n", BSTGetNodeData(searchNode));
}

void RemoveNode(BTreeNode ** pRoot, BSTData data)
{
    BSTShowAll(*pRoot);
    printf("\n");
    BTreeNode * searchNode = BSTRemove(pRoot, data);
    free(searchNode);
}

int main(void)
{
    BTreeNode * bstRoot;
    BSTMakeAndInit(&bstRoot);

    BSTInsert(&bstRoot, 5);
    BSTInsert(&bstRoot, 8);
    BSTInsert(&bstRoot, 1);
    BSTInsert(&bstRoot, 6);
    BSTInsert(&bstRoot, 4);
    BSTInsert(&bstRoot, 9);
    BSTInsert(&bstRoot, 3);
    BSTInsert(&bstRoot, 2);
    BSTInsert(&bstRoot, 7);

    SearchNode(bstRoot, 1);
    SearchNode(bstRoot, 4);
    SearchNode(bstRoot, 6);
    SearchNode(bstRoot, 7);

    RemoveNode(&bstRoot, 3);
    RemoveNode(&bstRoot, 8);
    RemoveNode(&bstRoot, 1);
    RemoveNode(&bstRoot, 6);

    BSTShowAll(bstRoot);
    printf("\n");

	BTreeNode * avlRoot;
	BTreeNode * clNode;		// current left node
	BTreeNode * crNode;		// current right node

	BTreeNode * clNode2;    
	BTreeNode * crNode2;

	BTreeNode * clNode3;
	BTreeNode * crNode3;

	BSTMakeAndInit(&avlRoot);

	BSTInsert(&avlRoot, 1);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 3);
	BSTInsert(&avlRoot, 4);
	BSTInsert(&avlRoot, 5);
	BSTInsert(&avlRoot, 6);
	BSTInsert(&avlRoot, 7);
	BSTInsert(&avlRoot, 8);
	BSTInsert(&avlRoot, 9);

	printf("루트 노드: %d \n", GetData(avlRoot));    //4

	clNode = GetLeftSubTree(avlRoot);   //2, 루트 4의 왼편
	crNode = GetRightSubTree(avlRoot);  //6, 루트 4의 오른편
	printf("%d, %d \n", GetData(clNode), GetData(crNode));

	clNode2 = GetLeftSubTree(clNode);    //1, 2의 왼편
	crNode2 = GetRightSubTree(clNode);   //3, 2의 오른편
	printf("%d, %d \n", GetData(clNode2), GetData(crNode2));

	clNode2 = GetLeftSubTree(crNode);    //5, 3의 왼편
	crNode2 = GetRightSubTree(crNode);   //8, 3의 오른편
	printf("%d, %d \n", GetData(clNode2), GetData(crNode2));

	clNode3 = GetLeftSubTree(crNode2);   //7, 8의 왼편
	crNode3 = GetRightSubTree(crNode2);  //9, 8의 오른편
	printf("%d, %d \n", GetData(clNode3), GetData(crNode3));
    
    return 0;
}
