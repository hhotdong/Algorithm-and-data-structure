// 홍정모 연구소, <자료구조 압축코스>
#pragma once

#include <cassert>
#include <iostream>
#include <iomanip>

template<typename T>
class Queue // Circular Queue
{
public:
    Queue(int capacity = 2)
    {
        assert(capacity > 0);

        capacity_ = capacity;
        queue_ = new T[capacity_];
        front_ = rear_ = 0;
    }

    ~Queue()
    {
        if (queue_) delete[] queue_;
    }

    bool IsEmpty() const
    {
        return front_ == rear_;
    }

    bool IsFull() const
    {
        // 원형 큐에서 꽉 찼다의 기준
        return (rear_ + 1) % capacity_ == front_;
    }

    T& Front() const
    {
        assert(!IsEmpty());

        return queue_[(front_ + 1) % capacity_]; // 주의 + 1
    }

    T& Rear() const
    {
        assert(!IsEmpty());

        return queue_[rear_];
    }

    int Size() const
    {
        if (front_ < rear_)
            return rear_ - front_;
        else if (front_ > rear_)
            return capacity_ - (front_ - rear_);
        else
           return 0; 
    }

    void Resize() // 2배씩 증가
    {
        T* new_queue = new T[2 * capacity_];
        int count = 1;
        for (int i = (front_ + 1) % capacity_; i != (rear_ + 1) % capacity_; i = (i + 1) % capacity_)
        {
            new_queue[count] = queue_[i];
            count++;
        }
        front_ = 0;
        rear_ = capacity_ - 1;
        capacity_ *= 2;
        delete[] queue_;
        queue_ = new_queue;
    }

    void Enqueue(const T& item) // 맨 뒤에 추가, Push()
    {
        if (IsFull())
            Resize();
        rear_ = (rear_ + 1) % capacity_;
        queue_[rear_] = item;
    }

    void Dequeue() // 큐의 첫 요소 삭제, Pop()
    {
        assert(!IsEmpty());
        front_ = (front_ + 1) % capacity_;    
    }

    void Print()
    {
        using namespace std;

        for (int i = (front_ + 1) % capacity_; i != (rear_ + 1) % capacity_; i = (i + 1) % capacity_)
            cout << queue_[i] << " ";
        cout << endl;

        if (print_debug_)
            PrintDebug();
    }

    void PrintDebug()
    {
        using namespace std;

        cout << "Cap = " << capacity_ << ", Size = " << Size();
        cout << endl;

        // front와 rear 위치 표시
        for (int i = 0; i < capacity_; i++) {
            if (i == front_) cout << " F ";
            else if (i == rear_) cout << " R ";
            else cout << "   ";
        }
        cout << endl;

        // 0 based index
        for (int i = 0; i < capacity_; i++)
            cout << setw(2) << i << " ";
        cout << endl;

        if (front_ < rear_)
        {
            // front 앞 사용하지 않은 공간
            for (int i = 0; i < front_ + 1; i++)
                cout << " - ";

            // 저장된 내용물
            for (int i = front_ + 1; i <= rear_; i++)
                cout << setw(2) << queue_[i] << " ";

            // rear 뒤 사용하지 않은 공간
            for (int i = rear_ + 1; i < capacity_; i++)
                cout << " * ";

            cout << endl << endl;
        }
        else if (front_ > rear_)
        {
            // rear 이전에 저장된 내용물
            for (int i = 0; i <= rear_; i++)
                cout << setw(2) << queue_[i] << " ";

            // rear와 front 사이 사용하지 않은 공간
            for (int i = rear_ + 1; i <= front_; i++)
                cout << " * ";

            // front 뒤 내용물
            for (int i = front_ + 1; i < capacity_; i++)
                cout << setw(2) << queue_[i] << " ";

            cout << endl << endl;
        }
        else // 비었을 경우
        {
            for (int i = 0; i < capacity_; i++)
                cout << " - ";
            cout << endl << endl;
        }
    }

    void SetDebugFlag(bool flag)
    {
        print_debug_ = flag;
    }

protected: // 뒤에서 상속해서 사용
    T* queue_; // array for queue elements
    int front_ = 0; // 시작 인덱스보다 하나 작은 값
    int rear_ = 0; // 마지막 인덱스 (첫 값은 1에 추가)
    int capacity_; // 빈 칸을 하나 둬야 하기 때문에 필요 메모리는 최대 저장량 + 1
    bool print_debug_ = false;
};
