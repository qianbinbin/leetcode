#include "find_minimum_in_rotated_sorted_array_ii.h"

int findMin_154_1(int *nums, int numsSize) {
    int start = 0, end = numsSize - 1, mid;
    while (start < end && nums[start] >= nums[end]) {
        mid = start + (end - start) / 2;
        if (nums[mid] > nums[end])
            start = mid + 1;
        else if (nums[mid] < nums[start])
            end = mid;
        else
            --end;
    }
    return nums[start];
}
