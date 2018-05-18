#include <first_missing_positive.h>
#include <stddef.h>

static void swap_int(int *a, int *b) {
    if (a != b) {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}

int firstMissingPositive_41(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 1) return 1;

    for (int i = 0; i < numsSize; ++i) {
        while (0 < nums[i] && nums[i] <= numsSize /* && nums[i] != i + 1 */ && nums[nums[i] - 1] != nums[i])
            swap_int(nums + i, nums + nums[i] - 1);
    }
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != i + 1)
            return i + 1;
    }
    return numsSize + 1;
}
