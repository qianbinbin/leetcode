#include "sort_colors.h"

#include <stddef.h>

void sortColors_75_1(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 2) return;
    int count0 = 0, count1 = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == 0)
            ++count0;
        else if (nums[i] == 1)
            ++count1;
    }
    int i = 0;
    for (; i < count0; ++i)
        nums[i] = 0;
    count1 += count0;
    for (; i < count1; ++i)
        nums[i] = 1;
    for (; i < numsSize; ++i)
        nums[i] = 2;
}

static void swap(int *a, int *b) {
    if (a != b) {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}

void sortColors_75_2(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 2) return;
    int i0 = 0, i2 = numsSize - 1;
    for (int i1 = 0; i1 <= i2;) {
        if (nums[i1] == 0) {
            swap(nums + i1++, nums + i0++);
        } else if (nums[i1] == 2) {
            swap(nums + i1, nums + i2--);
        } else {
            ++i1;
        }
    }
}
