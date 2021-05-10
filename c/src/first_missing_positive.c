#include "first_missing_positive.h"

static void swap(int *a, int *b) {
    if (a == b)
        return;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int firstMissingPositive_41_1(int *nums, int numsSize) {
    for (int i = 0, val; i < numsSize; ++i) {
        while ((val = nums[i]) != i + 1 && 0 < val && val <= numsSize &&
               nums[val - 1] != val)
            swap(nums + i, nums + val - 1);
    }
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != i + 1)
            return i + 1;
    }
    return numsSize + 1;
}
