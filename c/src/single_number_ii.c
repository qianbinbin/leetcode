#include "single_number_ii.h"

int singleNumber_137_1(int *nums, int numsSize) {
    int one = 0, two = 0;
    for (int i = 0; i < numsSize; ++i) {
        one = (one ^ nums[i]) & ~two;
        two = (two ^ nums[i]) & ~one;
    }
    return one;
}
