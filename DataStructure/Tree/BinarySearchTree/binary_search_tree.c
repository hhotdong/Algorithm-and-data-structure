// 윤성우의 <열혈 자료구조>
#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"
#include "AVLRebalance.h"

void BSTMakeAndInit(BTreeNode ** pRoot)
{
    *pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
    return GetData(bst);
}

/*
void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
    BTreeNode * parentNode  = NULL;
    BTreeNode * currentNode = *pRoot;
    BTreeNode * newNode     = NULL;

    while (currentNode != NULL)
    {
        // 키 값의 중복을 허용하지 않음.
        if (data == GetData(currentNode))
            return;

        parentNode = currentNode;
        
        if (GetData(currentNode) > data)
            currentNode = GetLeftSubTree(parentNode);
        else
            currentNode = GetRightSubTree(parentNode);
    }

    newNode = MakeBTreeNode();
    SetData(newNode, data);

    // 새 노드가 루트 노드인 경우
    if (parentNode == NULL)
        *pRoot = newNode;
    else
    {
        if (data < GetData(parentNode))
            MakeLeftSubTree(parentNode, newNode);
        else
            MakeRightSubTree(parentNode, newNode);
    }

    *pRoot = Rebalance(pRoot);
}
*/

// 새로 추가되는 노드의 부모들에 대하여 리밸런싱 여부를 재귀적으로 판담함으로써 보다 완전하게 불균형을 해소하는 구현.
BTreeNode * BSTInsert(BTreeNode ** pRoot, BSTData data)
{
    if (*pRoot == NULL)
	{
		*pRoot = MakeBTreeNode();
		SetData(*pRoot, data);
	}
	else if (data < GetData(*pRoot))
	{
		BSTInsert(&((*pRoot)->left), data);
		*pRoot = Rebalance(pRoot);
	}
	else if (data > GetData(*pRoot))
	{
		BSTInsert(&((*pRoot)->right), data);
		*pRoot = Rebalance(pRoot);
	}
	else
	{
		return NULL;  // 키의 중복을 허용하지 않음.
	}
	return *pRoot;
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
    BTreeNode * currentNode = bst;
    BSTData     currentData;

    while (currentNode != NULL)
    {
        currentData = GetData(currentNode);

        if (currentData == target)
            return currentNode;
        else if (currentData > target)
            currentNode = GetLeftSubTree(currentNode);
        else
            currentNode = GetRightSubTree(currentNode);
    }
    return NULL;
}

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target)
{
    // 삭제 대상이 루트 노드인 경우를 별도로 고려해야 한다.
    BTreeNode * pVirtualRoot = MakeBTreeNode();
    BTreeNode * parentNode   = pVirtualRoot;
    BTreeNode * currentNode  = *pRoot;
    BTreeNode * deleteNode;

    // 루트 노드를 pVirtualRoot가 가리키는 노드의 오른쪽 자식 노드가 되게 한다.
    ChangeRightSubTree(pVirtualRoot, *pRoot);

    // 삭제 대상인 노드를 탐색
    while (currentNode != NULL && GetData(currentNode) != target)
    {
        parentNode = currentNode;

        if (target < GetData(currentNode))
            currentNode = GetLeftSubTree(currentNode);
        else
            currentNode = GetRightSubTree(currentNode);
    }

    // 삭제 대상이 존재하지 않는 경우
    if (currentNode == NULL)
        return NULL;

    deleteNode = currentNode;

    // 첫 번째 경우: 삭제 대상이 단말 노드인 경우
    if (GetLeftSubTree(deleteNode) == NULL && GetRightSubTree(deleteNode) == NULL)
    {
        if (GetLeftSubTree(parentNode) == deleteNode)
            RemoveLeftSubTree(parentNode);
        else
            RemoveRightSubTree(parentNode);
    }
    // 두 번째 경우: 삭제 대상이 하나의 자식 노드를 갖는 경우
    else if (GetLeftSubTree(deleteNode) == NULL || GetRightSubTree(deleteNode) == NULL)
    {
        BTreeNode * deleteChildNode;

        if (GetLeftSubTree(deleteNode) != NULL)
            deleteChildNode = GetLeftSubTree(deleteNode);
        else
            deleteChildNode = GetRightSubTree(deleteNode);

        if (GetLeftSubTree(parentNode) == deleteNode)
            ChangeLeftSubTree(parentNode, deleteChildNode);
        else
            ChangeRightSubTree(parentNode, deleteChildNode);
    }
    // 세 번째 경우: 두 개의 자식 노드를 모두 갖는 경우
    else
    {
        BTreeNode * mNode = GetRightSubTree(deleteNode);  // 대체 노드를 가리킴.
        BTreeNode * mpNode = deleteNode;                  // 대체 노드의 부모 노드를 가리킴.
        int delData;

        // 삭제 대상의 대체 노드를 찾는다.
        while (GetLeftSubTree(mNode) != NULL)
        {
            mpNode = mNode;
            mNode = GetLeftSubTree(mNode);
        }

        // 대체 노드에 저장된 값을 삭제할 노드에 대입한다.
        delData = GetData(deleteNode);
        SetData(deleteNode, GetData(mNode));

        // 대체 노드의 부모 노드와 자식 노드를 연결한다.
        if (GetLeftSubTree(mpNode) == mNode)
            ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
        else
            ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

        deleteNode = mNode;
        SetData(deleteNode, delData);  // 백업 데이터 복원
    }
    
    // 삭제된 노드가 루트 노드인 경우에 대한 추가적인 처리
    if (GetRightSubTree(pVirtualRoot) != *pRoot)
        *pRoot = GetRightSubTree(pVirtualRoot);  // 루트 노드의 변경을 반영

    free(pVirtualRoot);

    *pRoot = Rebalance(pRoot);
    return deleteNode;
}

void ShowIntData(int data)
{
    printf("%d ", data);
}

void BSTShowAll(BTreeNode * bst)
{
    InorderTraverse(bst, ShowIntData);
}
