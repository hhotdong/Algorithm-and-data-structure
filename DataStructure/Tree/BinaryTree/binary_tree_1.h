// 홍정모 연구소, <자료구조 압축코스>
#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "../shared/array_base_stack_1.h"
#include "../shared/circular_queue_1.h"

template<typename T>
class BinaryTree
{
public:
	struct Node
	{
		T item = T();
		Node* left  = nullptr; // Left child
		Node* right = nullptr; // Right child
	};

	// 디버깅 도구: 큐에서 주소 대신에 아이템 출력
	class MyQueue : public Queue<Node*>
	{
	public:
		void Print()
		{
			using namespace std;

			for (int i = (this->front_ + 1) % this->capacity_; i != (this->rear_ + 1) % this->capacity_; i = (i + 1) % this->capacity_)
				cout << this->queue_[i]->item << " ";
			cout << endl;
		}
	};

	// 디버깅 도구: 스택에서 주소 대신에 아이템 출력
	class MyStack : public Stack<Node*>
	{
	public:
		void Print()
		{
			using namespace std;

			for (int i = 0; i < this->Size(); i++)
				cout << this->stack_[i]->item << " ";
			cout << endl;
		}
	};

	BinaryTree() {}

	BinaryTree(Node* root)
	{
		root_ = root;
	}

	bool IsEmpty()
	{
		return root_ == nullptr;
	}

	void Visit(Node* node)
	{
		using namespace std;
		cout << node->item << " ";
    }

	int Sum()
	{
		return Sum(root_);
	}

	int Sum(Node* node)
	{
        if (!node) return 0;
        return node->item + Sum(node->left) + Sum(node->right);
	}

	int Height()
	{
		return Height(root_);
	}

	int Height(Node* node)
	{
        if (!node) return 0;  // return -1 if the depth of root node is set to 0.
        return 1 + std::max(Height(node->left), Height(node->right));
	}

	~BinaryTree()
	{
		DeleteTree(root_);
	}

	void DeleteTree(Node* node)
	{
		if (node)
		{
			DeleteTree(node->left);
			DeleteTree(node->right);
            delete node;
		}
	}

	void Preorder() { Preorder(root_); }
	void Preorder(Node* node)
	{
        if (node)
        {    
		    Visit(node);
            Preorder(node->left);
            Preorder(node->right);
        }
	};

	void Inorder() { Inorder(root_); }
	void Inorder(Node* node)
	{
        if (node)
        {
            Inorder(node->left);
            Visit(node);
		    Inorder(node->right);
        }
	}

	void Postorder() { Postorder(root_); }
	void Postorder(Node* node)
	{
        if (node)
        {
            Postorder(node->left);
		    Postorder(node->right);
            Visit(node);
        }
	}

	void LevelOrder()
	{
		Queue<Node*> q;
        //MyQueue q;
        Node* current = root_;
		while (current)
		{
            Visit(current);
            if (current->left)  q.Enqueue(current->left);
			if (current->right) q.Enqueue(current->right);
            if (q.IsEmpty()) return;

            // cout << endl;
            // cout << "Queue: ";
            // q.Print();

            current = q.Front();
            q.Dequeue();
		}
	}

	void IterPreorder()
	{
        using namespace std;

        if (!root_) return;

        Stack<Node*> s;
        //MyStack s;
        s.Push(root_);

        while (!s.IsEmpty())
        {
            Node* current = s.Top();
            s.Pop();

            Visit(current);

            if (current->right) s.Push(current->right);
            if (current->left ) s.Push(current->left );

            //cout << "Stack: ";
            //s.Print();
        }
        /*      
		if (!root_) return;

		//Stack<Node*> s;
        MyStack s;
        Visit(root_);
		s.Push(root_);

		while (!s.IsEmpty())
		{
            Node* top = s.Top();

            if (top->left)
            {
                Visit(top->left);
                s.Push(top->left);
                continue;
            }
   
            if (top->right)
            {
                Visit(top->right);
                s.Push(top->right);
                continue;
            }

            while (1)
            {
                Node* curNode = s.Top();
                s.Pop();
                if (s.IsEmpty())
                {
                    break;
                }
                
                Node* parentNode = s.Top();
                if (curNode == parentNode->left && parentNode->right)
                {
                    Visit(parentNode->right);
                    s.Push(parentNode->right);
                    break;
                }
            }
		}
        */
	}

	void IterInorder()
	{
        using namespace std;
		
        if (!root_) return;

		Stack<Node*> s;
        //MyStack s;

		Node* current = root_;
		while (current || !s.IsEmpty())
		{
            while (current)
            {
                s.Push(current);
                current = current->left;
            }
            current = s.Top();
            s.Pop();
            Visit(current);
            current = current->right;

            /*
            if (current)
                s.Push(current);

            if (current && current->left)
            {
                current = current->left;
                continue;
            }

            while (true)
            {
                if (s.IsEmpty())
                {
                    current = nullptr;
                    break;
                }
                current = s.Top();
                s.Pop();
                Visit(current);
                if (current->right)
                {
                    current = current->right;
                    break;
                }
            }
            */
		}
	}

	void IterPostorder()
	{
		if (!root_) return;

		Stack<Node*> s1, s2;
		s1.Push(root_);

		while (!s1.IsEmpty())
		{
            Node* node = s1.Top();
            s1.Pop();
            s2.Push(node);
            
            if (node->left)
                s1.Push(node->left);
            if (node->right)
                s1.Push(node->right);
		}

		while (!s2.IsEmpty())
		{
            Node* node = s2.Top();
            s2.Pop();
			Visit(node);
		}
	}

	void Print2D();
	void PrintLevel(int n);
	void DisplayLevel(Node* p, int lv, int d);

protected:
	Node* root_ = nullptr;
};

// 디버깅 편의 도구
// https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
template<typename T>
void BinaryTree<T>::Print2D()
{
	using namespace std;
	int i = 0;
	while (i < Height()) {
		PrintLevel(i);
		i++;
		cout << endl;
	}
}

template<typename T>
void BinaryTree<T>::PrintLevel(int n) {
	using namespace std;
	Node* temp = root_;
	int val = (int)pow(2.0, Height() - n + 1.0);
	cout << setw(val) << "";
	DisplayLevel(temp, n, val);
}

template<typename T>
void BinaryTree<T>::DisplayLevel(Node* p, int lv, int d) {
	using namespace std;
	int disp = 2 * d;
	if (lv == 0) {
		if (p == NULL) {
			cout << "   ";
			cout << setw(disp - 3) << "";
			return;
		}
		else {
			int result = ((p->item <= 1) ? 1 : (int)log10(p->item) + 1);
			cout << " " << p->item << " ";
			cout << setw(static_cast<streamsize>(disp) - result - 2) << "";
		}
	}
	else
	{
		if (p == NULL && lv >= 1) {
			DisplayLevel(NULL, lv - 1, d);
			DisplayLevel(NULL, lv - 1, d);
		}
		else {
			DisplayLevel(p->left, lv - 1, d);
			DisplayLevel(p->right, lv - 1, d);
		}
	}
}
