#include "jump_game.h"

#include <stddef.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

bool canJump_55_1(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 1) return false;

    int farthest = 0;
    for (int i = 0; i < numsSize && i <= farthest; ++i) {
        farthest = MAX(farthest, nums[i] + i);
    }
    return farthest >= numsSize - 1;
}

bool canJump_55_2(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 1) return false;

    int remainder = 0;
    for (int i = 1; i < numsSize; ++i) {
        remainder = MAX(remainder, nums[i - 1]) - 1;
        if (remainder < 0)
            return false;
    }
    return true;
}
