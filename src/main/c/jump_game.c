#include <jump_game.h>
#include <stdlib.h>

bool canJump_55_1(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 1) return false;

    int farthest = 0;
    for (int i = 0; i < numsSize && farthest >= i; ++i) {
        if (nums[i] + i > farthest) {
            farthest = nums[i] + i;
        }
        if (farthest >= numsSize - 1) return true;
    }
    return false;
}

bool canJump_55_2(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 1) return false;

    int *remainder = (int *) malloc(numsSize * sizeof(int));
    remainder[0] = 0;
    for (int i = 1; i < numsSize; ++i) {
        remainder[i] = (remainder[i - 1] > nums[i - 1] ? remainder[i - 1] : nums[i - 1]) - 1;
        if (remainder[i] < 0) {
            free(remainder);
            return false;
        }
    }
    bool ret = remainder[numsSize - 1] >= 0;
    free(remainder);
    return ret;
}
