#include <maximum-subarray.h>
#include <limits.h>
#include <stddef.h>
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
    int max_with_beginning;
    int max_with_ending;
    int max;
    int total;
} sub_array;

static sub_array *new_sub(int mb, int me, int max, int total) {
    sub_array *new = (sub_array *) malloc(sizeof(sub_array));
    new->max_with_beginning = mb;
    new->max_with_ending = me;
    new->max = max;
    new->total = total;
    return new;
}

static sub_array *sub(int *nums, int start, int end) {
    if (start == end) return new_sub(nums[start], nums[start], nums[start], nums[start]);

    const int mid = start + (end - start) / 2;
    sub_array *left = sub(nums, start, mid);
    sub_array *right = sub(nums, mid + 1, end);
    int mb = MAX(left->max_with_beginning, left->total + right->max_with_beginning);
    int me = MAX(right->max_with_ending, right->total + left->max_with_ending);
    int max = MAX(left->max, right->max);
    max = MAX(max, left->max_with_ending + right->max_with_beginning);
    int total = left->total + right->total;
    free(left);
    free(right);
    return new_sub(mb, me, max, total);
}

int maxSubArray_53_2(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 1) return INT_MIN;

    sub_array *arr = sub(nums, 0, numsSize - 1);
    int ret = arr->max;
    free(arr);
    return ret;
}
