#include "remove_duplicates_from_sorted_array_ii.h"

#include <stddef.h>

int removeDuplicates_80_1(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 0) return -1;
    if (numsSize < 3) return numsSize;

    int size = 2;
    for (int i = 2; i < numsSize; ++i) {
        if (nums[i] != nums[size - 2]) {
            nums[size++] = nums[i];
        }
    }
    return size;
}
