// Credit: 홍정모 교수님의 <자료구조 압축코스>
#include <iostream>

// BestCase(이미 정렬되어 있거나 대부분 정렬되어 있는 경우)에서 삽입정렬의 연산횟수는 선택정렬에 비해 적다.
// stable: 정렬이 수행돼도 정렬 기준이 같은 원소들 간의 정렬 순서는 보장된다.
// 버블정렬의 swap은 3회의 대입연산을 수행하는데 비해 삽입정렬의 shift는 1회의 대입연산을 수행한다.
void InsertionSort(int arr[], int len)
{
    for (int i = 1; i < len; ++i)
    {
        int j = i;
        int key = arr[j];
        for (; j > 0 && arr[j - 1] > key; --j)
            arr[j] = arr[j - 1];
        arr[j] = key;
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
    int arr[] = { 1, 2, 4, 5, 3, 6 };
    int len   = sizeof(arr)/sizeof(arr[0]);
    
    Print(arr, len);
    InsertionSort(arr, len);
    Print(arr, len);

    return 0;
}