#include <single-number-ii.h>
#include <assert.h>
#include <stddef.h>
#include <string.h>

int singleNumber_137_1(int *nums, int numsSize) {
    assert(nums != NULL && numsSize > 0 && numsSize % 3 != 0);

    const int size = 8 * sizeof(int);
    int bitcount[size];
    memset(bitcount, 0, size * sizeof(int));
    for (int i = 0; i < numsSize; ++i) {
        for (int j = 0; j < size; ++j) {
            bitcount[j] += nums[i] >> j & 1;
        }
    }
    int ret = 0;
    for (int i = 0; i < size; ++i) {
        ret += bitcount[i] % 3 << i;
    }
    return ret;
}

int singleNumber_137_2(int *nums, int numsSize) {
    assert(nums != NULL && numsSize > 0 && numsSize % 3 != 0);

    int one = 0, two = 0;
    for (int i = 0; i < numsSize; ++i) {
        one = (one ^ nums[i]) & ~two;
        two = (two ^ nums[i]) & ~one;
    }
    return one;
}
