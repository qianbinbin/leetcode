#include <stddef.h>
#include <search_in_rotated_sorted_array_ii.h>

bool search_81(int *nums, int numsSize, int target) {
    if (nums == NULL || numsSize <= 0) return false;

    int begin = 0, end = numsSize - 1;
    int mid;
    while (begin <= end) {
        mid = begin + (end - begin) / 2;
        if (nums[mid] == target) {
            return true;
        }
        if (nums[begin] > nums[mid]) {
            if (nums[mid] < target && target <= nums[end]) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
        } else if (nums[begin] < nums[mid]) {
            if (nums[begin] <= target && target < nums[mid]) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        } else {
            ++begin;
        }
    }
    return false;
}
