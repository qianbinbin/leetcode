#include "find_minimum_in_rotated_sorted_array.h"

int findMin_153_1(int *nums, int numsSize) {
    int start = 0, end = numsSize - 1, mid;
    while (start < end && nums[start] > nums[end]) {
        mid = start + (end - start) / 2;
        if (nums[mid] > nums[end])
            start = mid + 1;
        else
            end = mid;
    }
    return nums[start];
}
