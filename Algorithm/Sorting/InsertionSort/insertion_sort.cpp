#include <iostream>

// unstable: 정렬이 수행될 때 정렬 기준이 같은 원소들 간의 기존 정렬 순서가 보장되지 않는다.
void InsertionSortA(int arr[], int len)
{
    for (int i = 1; i < len; ++i)
    {
        int j;
        int insData = arr[i];

        for (j = i - 1; j >= 0; --j)
        {
            if (arr[j] <= insData)
                break;
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = insData;
    }
}

void InsertionSortB(int arr[], int len)
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

    InsertionSortB(arr, len);
    Print(arr, len);

    return 0;
}
