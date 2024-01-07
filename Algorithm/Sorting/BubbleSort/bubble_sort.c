#include <stdio.h>

void Swap(int * a, int * b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - 1 - i; ++j)
        {
            if (arr[j] > arr[j + 1])
                Swap(&arr[j], &arr[j + 1]);
        }
    }
}

int main(void)
{
    int arr[10] = { 7, 9, 5, 6, 2, 3, 8, 4, 1, 0 };
    int len = sizeof(arr) / sizeof(arr[0]);

    BubbleSort(arr, len);

    for (int i = 0; i < len; ++i)
        printf("%d ", arr[i]);

    return 0;
}
