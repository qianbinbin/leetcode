#include <maximum-subarray.h>
#include <limits.h>
#include <stddef.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxSubArray_53_1(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 1) return INT_MIN;

    int dp = nums[0];
    int max = dp;
    for (int i = 1; i < numsSize; ++i) {
        dp = MAX(dp + nums[i], nums[i]);
        max = MAX(dp, max);
    }
    return max;
}
