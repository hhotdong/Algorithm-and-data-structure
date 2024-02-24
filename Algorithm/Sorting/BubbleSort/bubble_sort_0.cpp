// Credit: 홍정모 교수님의 <자료구조 압축코스>
#include <iostream>

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
