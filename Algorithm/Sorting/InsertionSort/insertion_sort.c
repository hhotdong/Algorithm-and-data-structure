#include <stdio.h>

void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
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

int main(void)
{
    int arr[10] = { 8, 2, 3, 9, 6, 4, 7, 5, 1 };
    int len = sizeof(arr) / sizeof(arr[0]);

    InsertionSort(arr, len);

    for (int i = 0; i < len; ++i)
        printf("%d ", arr[i]);

    return 0;
}
