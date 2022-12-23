#include <stdio.h>
#include <stdbool.h>  // bool, true, false

bool binary_search_leftmost(int target, int arr[], int len)
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
    return arr[first] == target;
}

bool binary_search_rightmost(int target, int arr[], int len)
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
    return arr[last - 1] == target;
}

int main(void)
{
    int arr[] = { 23, 44, 58, 79, 100 };
    
    int num = 0;
    printf("Enter number to search: ");
    scanf("%d", &num);
    
    bool found = binary_search_leftmost(num, arr, sizeof(arr) / sizeof(arr[0]));     
    printf("Number(%d) %s in the array.\n", num, found ? "found" : "not found");    

    found = binary_search_rightmost(num, arr, sizeof(arr) / sizeof(arr[0]));     
    printf("Number(%d) %s in the array.\n", num, found ? "found" : "not found");    
    return 0;
}
