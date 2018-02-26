#include <single-number.h>
#include <assert.h>
#include <stddef.h>

int singleNumber_136(int *nums, int numsSize) {
    assert(nums != NULL && numsSize > 2 && numsSize % 2 != 0);

    int ret = 0;
    for (int i = 0; i < numsSize; ++i) {
        ret ^= nums[i];
    }
    return ret;
}
