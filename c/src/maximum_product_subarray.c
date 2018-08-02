#include "maximum_product_subarray.h"

#include <stddef.h>


static int max(int a, int b) {
    return a > b ? a : b;
}


static int min(int a, int b) {
    return a < b ? a : b;
}

int maxProduct_152_1(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 1) return 0;

    int ret = nums[0];
    int dp_max = ret, dp_min = ret, tmp;
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] < 0) {
            tmp = dp_max;
            dp_max = dp_min;
            dp_min = tmp;
        }
        dp_max = max(nums[i], nums[i] * dp_max);
        dp_min = min(nums[i], nums[i] * dp_min);
        ret = max(ret, dp_max);
    }
    return ret;
}
