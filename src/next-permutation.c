#include <stdlib.h>
#include <next-permutation.h>

void swap(int *nums, int i, int j) {
    if (nums == NULL || i < 0 || j < 0 || i == j) return;

    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

void reverse(int *nums, int begin, int end) {
    if (nums == NULL || begin < 0 || end < 0 || begin >= end) return;

    int mid = begin + (end - begin + 1) / 2;
    for (int i = begin; i < mid; ++i) {
        swap(nums, i, end - i + begin);
    }
}

void nextPermutation_31(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 1) return;

    int i = numsSize - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) --i;
    if (i >= 0) {
        int j = i + 1;
        while (j < numsSize && nums[j] > nums[i]) ++j;
        swap(nums, i, j - 1);
    }
    reverse(nums, i + 1, numsSize - 1);
}
