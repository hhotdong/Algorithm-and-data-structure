// 홍정모 연구소, <자료구조 압축코스>
#pragma once

#include <cassert>
#include <stdint.h>
#include <algorithm>
#include <utility>

template<typename T>
class DoublyLinkedList
{
public:
	struct Node
	{
		T item = T();
		Node* left = nullptr;
		Node* right = nullptr;
	};

	DoublyLinkedList() { }

    DoublyLinkedList(const DoublyLinkedList& copy)
    {
        Node* tmp = copy.first_;
        while (tmp)
        {
            PushBack(tmp->item);
            tmp = tmp->right;
        }
    }

	~DoublyLinkedList()
	{
		Clear();
	}

	void Clear()
	{
        while (first_)
            PopFront();
	}

	bool IsEmpty()
	{
		return first_ == nullptr;
	}

	int Size()
	{
		int size = 0;
		Node* cur = first_;
        while (cur)
        {
            ++size;
            cur = cur->right;
        }
		return size;
	}

	void Print()
	{
		using namespace std;

		Node* current = first_;

		if (IsEmpty())
			cout << "Empty" << endl;
		else
		{
			cout << "Size = " << Size() << endl;

			cout << " Forward: ";
            Node* cur = first_;
            while (cur->right)
            {
                cout << cur->item << " ";
                cur = cur->right;
            }
            cout << cur->item;
			cout << endl;

            /*
			cout << " Forward: ";
            Node* cur = first_;
            while (true)
            {
                cout << cur->item << " ";
                if (!cur->right)
                    break;
                cur = cur->right;
            }
            */

			cout << "Backward: ";
		    while (cur->left)
            {
                cout << cur->item << " ";
                cur = cur->left;
            }
            cout << cur->item;
			cout << endl;
		}
	}

	Node* Find(T item)
	{
        Node* cur = first_;
        while (cur)
        {
            if (cur->item == item)
                return cur;
            cur = cur->right;
        }
		return nullptr;
	}

	void InsertBack(Node* node, T item)
	{
		if (IsEmpty())
		{
			PushBack(item);
		}
		else
		{
            Node* new_node = new Node;
            new_node->item = item;
            new_node->left = node;
            new_node->right = node->right;
            if (node->right)
                node->right->left = new_node;
            node->right = new_node;
		}
	}

	void PushFront(T item)
	{
		Node* new_node = new Node;
        new_node->item = item;
        new_node->left = nullptr;
        new_node->right = first_;
        if (first_)
            first_->left = new_node;
        first_ = new_node;
	}

	void PushBack(T item)
	{
        if (IsEmpty())
        {
            PushFront(item);
            return;
        }
        Node* cur = first_;
        while (cur->right)
            cur = cur->right;
        Node* new_node = new Node;
        new_node->item = item;
        new_node->left = cur;
        new_node->right = nullptr;
        cur->right = new_node;
	}

	void PopFront()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopFront()" << endl;
			return;
		}

		assert(first_);
	    Node* del_node = first_;
        first_ = del_node->right;
        if (first_)
            first_->left = nullptr;
        delete del_node;
	}

	void PopBack()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopBack()" << endl;
			return;
		}

		assert(first_);
        Node* cur = first_;
        while (cur->right)
            cur = cur->right;
        Node* second_last = cur->left;
        delete cur;
        if (second_last)
            second_last->right = nullptr;
        else
            first_ = nullptr;

        /*
        assert(first_);
        Node* cur = first_;
        if (cur->right)
        {
            while (cur->right->right)
                cur = cur->right;

            Node* temp = cur->right;
            cur->right = cur->right->right;

            delete temp;
        }
        else
        {
            delete first_;
            first_ = nullptr;
        }
        */
	}

	void Reverse()
	{
        /*
        if (IsEmpty())
            return;

        Node* cur  = first_;
        Node* prev = nullptr;

        while (cur)
        {
            prev = cur;
            cur = cur->right;
            std::swap(prev->left, prev->right);
        }

        first_ = prev;
        */

		Node* cur = first_;
        while (cur)
        {
            Node* next = cur->right;
            std::swap(cur->left, cur->right);
            if (next == nullptr)
                first_ = cur;
            cur = next;
        }
	}

	T Front()
	{
		assert(first_);
		return first_->item;
	}

	T Back()
	{
		assert(first_);
        Node* cur = first_;
        while (cur->right)
            cur = cur->right;
        return cur->item;
	}

protected:
	Node* first_ = nullptr;
};
