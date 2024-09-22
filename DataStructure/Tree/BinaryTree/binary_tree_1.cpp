// 홍정모 연구소, <자료구조 압축코스>
#include <iostream>
#include "binary_tree_1.h"

using namespace std;

int main()
{
    // 배열로도 구현 가능

    using Node = BinaryTree<int>::Node;

    Node* n1 = new Node{ 1, nullptr, nullptr }; // 물결괄호 초기값 나열 (생성자 아님)
    Node* n2 = new Node{ 2, n1, nullptr };
    Node* n3 = new Node{ 3, nullptr, nullptr };
    Node* n4 = new Node{ 4, nullptr, nullptr };
    Node* n5 = new Node{ 5, nullptr, n4 };
    Node* n6 = new Node{ 6, n2, n5 };

    n1->right = n3; // <- 연결관계 변경

    BinaryTree<int> tree(n6); // <- n6의 주소를 root node로 

    tree.Print2D();

    cout << "Sum: " << tree.Sum() << endl;        // Sum: 21
    cout << "Height: " << tree.Height() << endl;  // Height : 4

    // Tree traversal methods

    cout << "Preorder" << endl; // 6 2 1 3 5 4
    tree.Preorder();
    cout << endl;

    cout << "Inorder" << endl; // 1 3 2 6 5 4
    tree.Inorder();
    cout << endl;

    cout << "Postorder" << endl; // 3 1 2 4 5 6
    tree.Postorder();
    cout << endl;

    cout << "LevelOrder" << endl; // 6 2 5 1 4 3
    tree.LevelOrder();
    cout << endl;

    cout << "Iterative Preorder" << endl; // 6 2 1 3 5 4
    tree.IterPreorder();
    cout << endl;

    cout << "Iterative Inorder" << endl; // 1 3 2 6 5 4
    tree.IterInorder();
    cout << endl;

    cout << "Iterative Postorder" << endl; // 3 1 2 4 5 6
    tree.IterPostorder();
    cout << endl;

    return 0;
}