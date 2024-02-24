// Credit: 홍정모 교수님의 <자료구조 압축코스>
#include <iostream>

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