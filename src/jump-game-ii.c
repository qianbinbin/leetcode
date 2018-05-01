#include <jump-game-ii.h>
#include <stddef.h>

int jump_45_1(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 1) return -1;
    if (numsSize == 1) return 0;

    int i = 0;
    int farthest = 0, next_farthest = 0;
    int depth = 0;
    while (i <= farthest) {
        for (; i <= farthest; ++i) {
            next_farthest = i + nums[i] > next_farthest ? i + nums[i] : next_farthest;
            if (next_farthest >= numsSize - 1) return depth + 1;
        }
        farthest = next_farthest;
        ++depth;
    }
    return -1;
}

int jump_45_2(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 1) return -1;

    int farthest = 0, last_farthest = 0;
    int step = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (i > last_farthest) {
            last_farthest = farthest;
            ++step;
        }
        farthest = i + nums[i] > farthest ? i + nums[i] : farthest;
    }
    return step;
}
