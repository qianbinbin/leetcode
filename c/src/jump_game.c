#include "jump_game.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

bool canJump_55_1(int *nums, int numsSize) {
    int farthest = 0;
    for (int i = 0; i <= farthest && farthest + 1 < numsSize; ++i) {
        farthest = MAX(farthest, nums[i] + i);
    }
    return farthest >= numsSize - 1;
}

bool canJump_55_2(int *nums, int numsSize) {
    int remainder = 0;
    int i;
    for (i = 0; i < numsSize && remainder >= 0; ++i) {
        remainder = MAX(remainder, nums[i]) - 1;
    }
    return i == numsSize;
}
