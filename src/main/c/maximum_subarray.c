#include "maximum_subarray.h"

#include <limits.h>
#include <stdlib.h>

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

typedef struct {
    int max_begin;
    int max_end;
    int max;
    int total;
} array_sum;

static array_sum *new_array_sum(int mb, int me, int max, int total) {
    array_sum *new = (array_sum *) malloc(sizeof(array_sum));
    new->max_begin = mb;
    new->max_end = me;
    new->max = max;
    new->total = total;
    return new;
}

static array_sum *sub(int *nums, int start, int end) {
    if (start + 1 == end)
        return new_array_sum(nums[start], nums[start], nums[start], nums[start]);

    const int mid = start + (end - start) / 2;
    array_sum *left = sub(nums, start, mid);
    array_sum *right = sub(nums, mid, end);
    int mb = MAX(left->max_begin, left->total + right->max_begin);
    int me = MAX(right->max_end, right->total + left->max_end);
    int max = MAX(left->max, right->max);
    max = MAX(max, left->max_end + right->max_begin);
    int total = left->total + right->total;
    free(left);
    free(right);
    return new_array_sum(mb, me, max, total);
}

int maxSubArray_53_2(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 1) return INT_MIN;

    array_sum *arr = sub(nums, 0, numsSize);
    int ret = arr->max;
    free(arr);
    return ret;
}
