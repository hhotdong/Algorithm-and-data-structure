#include <stdio.h>

// If target is found in the given array, return the index of the leftmost element. If not, return -1.
int binary_search_leftmost(int target, int arr[], int len)
{
    int first = 0;
    int last  = len;
    
    while (first < last)
    {
        int mid = first + (last - first) / 2;
        if (arr[mid] < target)
            first = mid + 1;
        else
            last = mid;
    }

    if (arr[first] == target)
        return first;
    return -1;
}

// If target is found in the given array, return the index of the rightmost element. If not, return -1.
int binary_search_rightmost(int target, int arr[], int len)
{
    int first = 0;
    int last  = len;
    
    while (first < last)
    {
        int mid = first + (last - first) / 2;
        if (arr[mid] > target)
            last = mid;
        else
            first = mid + 1;
    }
    
    if (arr[last - 1] == target)
        return last - 1;
    return -1;
}

int main(void)
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 8, 8, 9, 10 };
    
    int num = 0;
    printf("Enter number to search between 1 and 10: ");
    scanf("%d", &num);
    
    int leftmost_idx = binary_search_leftmost(num, arr, sizeof(arr) / sizeof(arr[0]));
    if (leftmost_idx == -1)
        printf("Number(%d) not found.\n", num);
    else
        printf("Number(%d) found at index(%d) in the array.\n", num, leftmost_idx);

    int rightmost_idx = binary_search_rightmost(num, arr, sizeof(arr) / sizeof(arr[0]));
    if (rightmost_idx == -1)
        printf("Number(%d) not found.\n", num);
    else
        printf("Number(%d) found at index(%d) in the array.\n", num, rightmost_idx);
    return 0;
}
