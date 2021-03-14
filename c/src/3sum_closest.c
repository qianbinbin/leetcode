#include "3sum_closest.h"

#include <stdlib.h>

static int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int threeSumClosest_16_1(int *nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compare);
    int ret = nums[0] + nums[1] + nums[2], sum;
    int i, j, k, e = numsSize - 2;
    for (i = 0; i < e;) {
        j = i + 1;
        k = numsSize - 1;
        while (j < k) {
            sum = nums[i] + nums[j] + nums[k];
            if (abs(sum - target) < abs(ret - target))
                ret = sum;
            if (sum < target) {
                do { ++j; } while (j < k && nums[j] == nums[j - 1]);
            } else if (sum > target) {
                do { --k; } while (j < k && nums[k] == nums[k + 1]);
            } else {
                return ret;
            }
        }
        do { ++i; } while (i < e && nums[i] == nums[i - 1]);
    }
    return ret;
}
