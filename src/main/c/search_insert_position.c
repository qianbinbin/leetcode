#include "search_insert_position.h"

#include <stddef.h>

int searchInsert_35_1(int *nums, int numsSize, int target) {
    if (nums == NULL || numsSize < 0) return -1;

    int begin = 0, end = numsSize - 1, mid = 0, val;
    while (begin <= end) {
        mid = begin + (end - begin) / 2;
        val = nums[mid];
        if (val == target)
            return mid;
        if (val > target)
            end = mid - 1;
        else
            begin = mid + 1;
    }
    return begin;
}
