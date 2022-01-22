#include "sort_colors.h"

void sortColors_75_1(int *nums, int numsSize) {
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
    int last0 = -1, first2 = numsSize;
    for (int i = 0; i < first2;) {
        if (nums[i] == 0)
            swap(nums + ++last0, nums + i++);
        else if (nums[i] == 2)
            swap(nums + i, nums + --first2);
        else
            ++i;
    }
}
