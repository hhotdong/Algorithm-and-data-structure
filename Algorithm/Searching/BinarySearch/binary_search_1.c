#include <stdio.h>
#include <stdbool.h>  // bool, true, false

bool binary_search_recursive(int target, int arr[], int first, int last)
{
    if (first > last)
        return false;

    int mid = first + (last - first) / 2;

    if (target == arr[mid])
        return true;
    else if (target < arr[mid])
        return binary_search_recursive(target, arr, first  , mid - 1);
    else
        return binary_search_recursive(target, arr, mid + 1, last);
}

int main(void)
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    
    int num = 0;
    printf("Enter number to search between 1 and 10: ");
    scanf("%d", &num);
    
    bool found = binary_search_recursive(num, arr, 0, sizeof(arr) / sizeof(arr[0]));     
    printf("Number(%d) %s in the array.\n", num, found ? "found" : "not found");    

    return 0;
}
