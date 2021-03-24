#include "find_first_and_last_position_of_element_in_sorted_array.h"

#include <stdbool.h>
#include <stdlib.h>

static int
insert_index(int const *array, int begin, int end, int value, bool before) {
    int mid, val;
    while (begin < end) {
        mid = begin + (end - begin) / 2;
        val = array[mid];
        if (val > value || (before && val == value))
            end = mid;
        else
            begin = mid + 1;
    }
    return begin;
}

int *searchRange_34_1(int *nums, int numsSize, int target, int *returnSize) {
    int *ret = (int *) malloc(2 * sizeof(int));
    int index = insert_index(nums, 0, numsSize, target, true);
    if (index == numsSize || nums[index] != target) {
        ret[0] = -1;
        ret[1] = -1;
    } else {
        ret[0] = index;
        ret[1] = insert_index(nums, index, numsSize, target, false) - 1;
    }
    *returnSize = 2;
    return ret;
}
