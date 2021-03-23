#include "search_in_rotated_sorted_array.h"

int search_33_1(int *nums, int numsSize, int target) {
    int begin = 0, end = numsSize - 1, mid;
    while (begin <= end) {
        mid = begin + (end - begin) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[begin] <= nums[mid]) {
            if (nums[begin] <= target && target < nums[mid])
                end = mid - 1;
            else
                begin = mid + 1;
        } else {
            if (nums[mid] < target && target <= nums[end])
                begin = mid + 1;
            else
                end = mid - 1;
        }
    }
    return -1;
}
