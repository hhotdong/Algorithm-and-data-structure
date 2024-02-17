#include <iostream>

// 이미 정렬되어 있거나 대부분 정렬되어 컬렉션의 경우 버블정렬의 연산횟수는 선택정렬에 비해 적다.
// stable: 정렬이 수행돼도 정렬 기준이 같은 원소들 간의 정렬 순서는 보장된다.
void BubbleSortA(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - 1 - i; ++j)
        {
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
        }
    }
}

void BubbleSortB(int arr[], int n)
{
    for (int i = n - 1; i > 0; --i)
    {
        bool swapped = false;
        for (int j = 0; j < i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swapped = true;
                std::swap(arr[j], arr[j + 1]);
            }
        }
        
        if (swapped == false)
            return;
    }
}

void Print(int arr[], int len)
{
    for (int i = 0; i < len; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main(void)
{
    int arr[] = { 5, 4, 3, 2, 1 };
    int len   = sizeof(arr) / sizeof(arr[0]);

    BubbleSortB(arr, len);
    Print(arr, len);

    return 0;
}
