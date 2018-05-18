#include <search_insert_position.h>
#include <stddef.h>

int searchInsert_35(int *nums, int numsSize, int target) {
    if (nums == NULL || numsSize < 0) return -1;
    int begin = 0, end = numsSize - 1, mid = 0;
    while (begin <= end) {
        mid = begin + (end - begin) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            begin = mid + 1;
        else
            end = mid - 1;
    }
    return begin;
}
