#include <stdio.h>
#include "../BinaryTree/binary_tree.h"

BTreeNode * RotateLL(BTreeNode * bst)
{
    BTreeNode * parentNode = bst;
    BTreeNode * childNode  = GetLeftSubTree(parentNode);

    ChangeLeftSubTree(parentNode, GetRightSubTree(childNode));
    ChangeRightSubTree(childNode, parentNode);
    return childNode;
}

BTreeNode * RotateRR(BTreeNode * bst)
{
    BTreeNode * parentNode = bst;
    BTreeNode * childNode  = GetRightSubTree(parentNode);

    ChangeRightSubTree(parentNode, GetLeftSubTree(childNode));
    ChangeLeftSubTree(childNode, parentNode);
    return childNode;
}

BTreeNode * RotateLR(BTreeNode * bst)
{
    BTreeNode * parentNode = bst;
    BTreeNode * childNode  = GetLeftSubTree(parentNode);

    ChangeLeftSubTree(parentNode, RotateRR(childNode));
    return RotateLL(parentNode);
}

BTreeNode * RotateRL(BTreeNode * bst)
{
    BTreeNode * parentNode = bst;
    BTreeNode * childNode  = GetRightSubTree(parentNode);

    ChangeRightSubTree(parentNode, RotateLL(childNode));
    return RotateRR(parentNode);
}

int GetHeight(BTreeNode * bst)
{
    if (bst == NULL)
        return 0;

    int leftH  = GetHeight(GetLeftSubTree(bst));
    int rightH = GetHeight(GetRightSubTree(bst));

    if (leftH > rightH)
        return leftH + 1;
    else
        return rightH + 1;
}

int GetHeightDiff(BTreeNode * bst)
{
    if (bst == NULL)
        return 0;

    int lsh = GetHeight(GetLeftSubTree(bst));
    int rsh = GetHeight(GetRightSubTree(bst));
    return lsh - rsh;
}

BTreeNode * Rebalance(BTreeNode ** pRoot)
{
    int hDiff = GetHeightDiff(*pRoot);
    if (hDiff > 1)
    {
        if (GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
            *pRoot = RotateLL(*pRoot);
        else
            *pRoot = RotateLR(*pRoot);
    }
    
    if (hDiff < -1)
    {
        if (GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
            *pRoot = RotateRR(*pRoot);
        else
            *pRoot = RotateRL(*pRoot);
    }
    return *pRoot;
}
