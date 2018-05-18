#include <stddef.h>
#include <search_in_rotated_sorted_array.h>

int search_33(int *nums, int numsSize, int target) {
    if (nums == NULL || numsSize < 0) return -2;

    int begin = 0, end = numsSize - 1;
    int mid;
    while (begin <= end) {
        mid = begin + (end - begin) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[begin] > nums[mid]) {
            if (nums[mid] < target && target <= nums[end]) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
        } else {
            if (nums[begin] <= target && target < nums[mid]) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
    }
    return -1;
}
