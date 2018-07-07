#include "search_in_rotated_sorted_array_ii.h"

#include <stddef.h>

bool search_81_1(int *nums, int numsSize, int target) {
    if (nums == NULL || numsSize <= 0) return false;

    int begin = 0, end = numsSize - 1, mid, mid_val;
    while (begin <= end) {
        mid = begin + (end - begin) / 2;
        mid_val = nums[mid];
        if (target == mid_val)
            return true;
        if (nums[begin] > mid_val) {
            if (mid_val < target && target <= nums[end])
                begin = mid + 1;
            else
                end = mid - 1;
        } else if (nums[begin] < mid_val) {
            if (nums[begin] <= target && target < mid_val)
                end = mid - 1;
            else
                begin = mid + 1;
        } else {
            while (begin < numsSize && nums[begin] == mid_val) ++begin;
        }
    }
    return false;
}
