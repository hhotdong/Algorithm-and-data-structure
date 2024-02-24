// Credit: 홍정모 교수님의 <자료구조 압축코스>
#include <iostream>

void SelectionSort(int arr[], int len)
{
    for (int i = 0; i < len - 1; ++i)
    {
        int minIdx = i;
        for (int j = i + 1; j < len; ++j)
        {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }

        if (minIdx != i)
            std::swap(arr[minIdx], arr[i]);
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
    int arr[] = { 8, 2, 3, 9, 6, 4, 7, 5, 1 };
    int len   = sizeof(arr) / sizeof(arr[0]);

    SelectionSort(arr, len);
    Print(arr, len);

    return 0;
}
