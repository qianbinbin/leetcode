#include "maximum_subarray.h"

#include <limits.h>

int maxSubArray_53_1(int *nums, int numsSize) {
    int dp = -1, ret = INT_MIN;
    for (int i = 0; i < numsSize; ++i) {
        dp = dp < 0 ? nums[i] : dp + nums[i];
        if (dp > ret) ret = dp;
    }
    return ret;
}
