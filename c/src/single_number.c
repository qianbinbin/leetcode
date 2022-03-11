#include "single_number.h"

int singleNumber_136_1(int *nums, int numsSize) {
    int ret = 0;
    for (int i = 0; i < numsSize; ++i)
        ret ^= nums[i];
    return ret;
}
