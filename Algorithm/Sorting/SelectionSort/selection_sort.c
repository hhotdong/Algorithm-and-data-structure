#include <stdio.h>

void Swap(int * a, int * b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int minIdx = i;
        for (int j = minIdx + 1; j < n; ++j)
        {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        Swap(&arr[i], &arr[minIdx]);
    }
}

int main(void)
{
    int arr[10] = { 8, 2, 3, 9, 6, 4, 7, 5, 1 };
    int len = sizeof(arr) / sizeof(arr[0]);

    SelectionSort(arr, len);

    for (int i = 0; i < len; ++i)
        printf("%d ", arr[i]);

    return 0;
}
