#include <stdio.h>
#include <stdbool.h>  // bool, true, false

bool binary_search(int target, int arr[], int len)
{
    int first = 0;
    int last  = len - 1;
    
    while (first <= last)
    {
        int mid = first +  (last - first) / 2;

        if (target == arr[mid])
            return true;
        else if (target < arr[mid]) 
            last = mid - 1;
        else
            first = mid + 1;
    }
    return false; 
}

int main(void)
{
    int arr[] = { 23, 44, 58, 79, 100 };
    
    int num = 0;
    printf("Enter number to search: ");
    scanf("%d", &num);
    
    bool found = binary_search(num, arr, sizeof(arr) / sizeof(arr[0]));     
    printf("Number(%d) %s in the array.\n", num, found ? "found" : "not found");    

    return 0;
}
