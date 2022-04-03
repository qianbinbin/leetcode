#include "next_permutation.h"

static void reverse(int *nums, int i, int j) {
    int tmp;
    for (; i < j; ++i, --j) {
        tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}

void nextPermutation_31_1(int *nums, int numsSize) {
    int i = numsSize - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) --i;
    if (i >= 0) {
        int j = i + 1;
        while (j < numsSize && nums[j] > nums[i]) ++j;
        int tmp = nums[i];
        nums[i] = nums[j - 1];
        nums[j - 1] = tmp;
    }
    reverse(nums, i + 1, numsSize - 1);
}
