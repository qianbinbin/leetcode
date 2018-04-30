#include <jump-game.h>
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
