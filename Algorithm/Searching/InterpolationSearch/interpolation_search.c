// 윤성우의 <열혈 자료구조>
#include <stdio.h>

int interpolation_search(int arr[], int first, int last, int target)
{
    int iIdx;

    if (arr[first] > target || arr[last] < target)
        return -1;

    iIdx = ((double)(target - arr[first]) / (arr[last] - arr[first]) * (last - first)) + first;

    if (arr[iIdx] == target)
        return iIdx;
    else if (target < arr[iIdx])
        return interpolation_search(arr, first, iIdx - 1, target);
    else
        return interpolation_search(arr, iIdx + 1, last, target);
}

int main(void)
{
    int arr[] = { 1, 3, 5, 7, 9 };    
    int idx = interpolation_search(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);
    if (idx == -1)
        printf("Search failed\n");
    else
        printf("Search succeeded: %d\n", idx);
    return 0;
}
