#include "search_for_a_range.h"

#include <stdbool.h>
#include <stdlib.h>

static int insert_index(int *array, int begin, int end, int value, bool before) {
    --end;
    int mid, mid_val;
    while (begin <= end) {
        mid = begin + (end - begin) / 2;
        mid_val = array[mid];
        if (mid_val > value || (before && mid_val == value))
            end = mid - 1;
        else
            begin = mid + 1;
    }
    return begin;
}

int *searchRange_34_1(int *nums, int numsSize, int target, int *returnSize) {
    if (nums == NULL || numsSize < 0 || returnSize == NULL) return NULL;

    *returnSize = 2;
    int *ret = (int *) malloc(2 * sizeof(int));
    int index = insert_index(nums, 0, numsSize, target, true);
    if (index == numsSize || nums[index] != target) {
        ret[0] = -1;
        ret[1] = -1;
    } else {
        ret[0] = index;
        ret[1] = insert_index(nums, index, numsSize, target, false) - 1;
    }
    return ret;
}
