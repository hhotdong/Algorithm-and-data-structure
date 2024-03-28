// Credit: https://medium.com/@simontoth/daily-bit-e-of-c-find-the-duplicate-value-72b9cae41c99 
#include <iostream>
#include <vector>

// Given an array of length n+1 that contains the integers 1..n with one duplicate, return the duplicate.
// Your solution should have O(n) time complexity and O(1) space complexity.
int duplicate_value_A(const std::vector<int>& nums) {
    int tortoise = nums[0];
    int hare = nums[0];

    // Advance until the tortoise meets the hare.
    do {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    } while (tortoise != hare);

    // Reset the tortoise and move both
    // one step at a time, until they meet.
    tortoise = nums[0];
    while (tortoise != hare) {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }

    return hare;
}

int duplicate_value_B(const std::vector<int>& nums) {
    int sumIncludingDuplicate = 0;
    for (auto& n : nums)
        sumIncludingDuplicate += n;
    
    int sumExcludingDuplicate = 0;
    for (int i = 1; i < nums.size(); ++i)
        sumExcludingDuplicate += i;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (sumIncludingDuplicate - nums[i] == sumExcludingDuplicate)
            return nums[i];
    }
    return -1;
}

int main(void)
{
    std::vector<int> nums = { 7, 1, 6, 9, 3, 4, 9, 5, 2, 8 };
    std::cout << "Duplicate value(A): " << duplicate_value_A(nums)  << std::endl;
    std::cout << "Duplicate value(B): " << duplicate_value_B(nums)  << std::endl;
    return 0;
}
