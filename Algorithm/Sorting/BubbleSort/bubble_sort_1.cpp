// Credit: 홍정모 교수님의 <자료구조 압축코스>
#include <iostream>

void BubbleSort(int arr[], int n)
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

    BubbleSort(arr, len);
    Print(arr, len);

    return 0;
}
