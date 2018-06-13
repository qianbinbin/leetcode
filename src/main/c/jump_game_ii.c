#include "jump_game_ii.h"

#include <stddef.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int jump_45_1(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 1) return -1;

    int farthest = 0, last_farthest = 0;
    int step = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (i > last_farthest) {
            last_farthest = farthest;
            ++step;
        }
        farthest = MAX(farthest, i + nums[i]);
    }
    return step;
}
