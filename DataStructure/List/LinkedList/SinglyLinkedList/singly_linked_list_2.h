// 홍정모 교수님, <자료구조 압축코스>
#pragma once

#include <cassert>
#include <stdint.h>

template<typename T>
class SinglyLinkedList
{
public:
    struct Node
    {
        T item = T();
        Node* next = nullptr;
    };

    SinglyLinkedList() { }

    SinglyLinkedList(const SinglyLinkedList& list)
    {
        Node* cur = list.first_;
        while (cur)
        {
            PushBack(cur->item);
            cur = cur->next;
        }
    }

    ~SinglyLinkedList()
    {
        Clear();
    }

    void Clear()
    {
        while (first_)
            PopFront();

        /*
        Node* del_node = first_;
        while (del_node)
        {
            Node* del_node_next = del_node->next;
            free(del_node);
            del_node = del_node_next;
        }
        */
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
            cur = cur->next;
        }
        return size;
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
        while (cur->next)
            cur = cur->next;
        return cur->item;
    }

    Node* Find(T item)
    {
        Node* cur = first_;

        while (cur)
        {
            if (cur->item == item)
                return cur;
            cur = cur->next;
        }
        return cur;  // nullptr
    }

    void InsertBack(Node* node, T item)
    {
        Node* new_node = new Node;
        new_node->item = item;
        new_node->next = node->next;
        node->next     = new_node;
    }

    void Remove(Node* node)
    {
        if (first_ == node)
        {
            first_ = first_->next;
            delete node;
            return;
        }

        Node* prev = first_;
        while (prev->next)
        {
            if (prev->next == node)
                break;
            prev = prev->next;
        }

        // 리스트 내에 해당 노드가 존재하지 않는 경우
        if (prev->next != node)
            return;
        
        prev->next = node->next;
        delete node;
    }

    void PushFront(T item)
    {
        Node* new_node = new Node;
        new_node->item = item;
        new_node->next = first_;
        first_         = new_node;
    }

    void PushBack(T item)
    {
        if (first_)
        {
            Node* new_node = new Node;
            new_node->item = item;
            new_node->next = nullptr;

            Node* cur = first_;
            while (cur->next)
                cur = cur->next;
            cur->next = new_node;
        }
        else
        {
            Node* new_node = new Node;
            new_node->item = item;
            new_node->next = nullptr;
            first_ = new_node;
        }
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
        Node* next = first_->next;
        delete first_;
        first_ = next;
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

        if (first_->next == nullptr)
        {
            delete first_;
            first_ = nullptr;
            return;
        }

        Node* second_last = first_;
        while (second_last->next->next)
            second_last = second_last->next;

        Node* temp = second_last->next;
        second_last->next = second_last->next->next;
        delete temp;
    }

    void Reverse()
    {
        Node* prev = nullptr;
        Node* cur  = first_;
        while (cur)
        {
            Node* pprev = prev;
            prev = cur;
            cur = cur->next;
            prev->next = pprev;
        }
        first_ = prev;
    }

    void SetPrintDebug(bool flag)
    {
        print_debug_ = flag;
    }

    void Print()
    {
        using namespace std;

        Node* current = first_;

        if (IsEmpty())
            cout << "Empty" << endl;
        else
        {
            cout << "Size = " << Size() << " ";

            while (current)
            {
                if (print_debug_)
                {
                    //cout << "[" << current << ", " << current->item << ", " << current->next << "]";

                    // 주소를 짧은 정수로 출력 (앞 부분은 대부분 동일하기때문에 뒷부분만 출력)
                    cout << "[" << reinterpret_cast<uintptr_t>(current) % 100000 << ", "
                        << current->item << ", "
                        << reinterpret_cast<uintptr_t>(current->next) % 100000 << "]";
                }
                else
                {
                    cout << current->item;
                }

                if (current->next)
                    cout << " -> ";
                else
                    cout << " -> NULL";

                current = current->next;
            }
            cout << endl;
        }
    }

protected:
    Node* first_ = nullptr;
    bool print_debug_ = false;
};
