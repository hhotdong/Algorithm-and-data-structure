// Credit: 홍정모 교수님의 <자료구조 압축코스>
#include <iostream>

// BestCase(이미 정렬되어 있거나 대부분 정렬되어 있는 경우)에서 버블정렬의 연산횟수는 선택정렬에 비해 적다.
// stable: 정렬이 수행돼도 정렬 기준이 같은 원소들 간의 정렬 순서는 보장된다.
void BubbleSort(int arr[], int n)
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

    BubbleSort(arr, len);
    Print(arr, len);

    return 0;
}
