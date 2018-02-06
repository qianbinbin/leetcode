#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <3sum-closest.h>

int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int threeSumClosest_16(int *nums, int numsSize, int target) {
    if (nums == NULL || numsSize < 3) {
        return INT_MAX;
    }

    int *tmp = (int *) malloc(numsSize * sizeof(int));
    assert(tmp != NULL);
    memcpy(tmp, nums, numsSize * sizeof(int));
    qsort(tmp, numsSize, sizeof(int), compare);

    int sum;
    int diff;
    int ret = INT_MAX, pre_abs = INT_MAX;
    int i, j, k;
    for (i = 0; i < numsSize - 2; ++i) {
        j = i + 1, k = numsSize - 1;
        while (j < k) {
            sum = tmp[i] + tmp[j] + tmp[k];
            diff = sum - target;
            ret = abs(diff) < pre_abs ? sum : ret;
            pre_abs = abs(diff) < pre_abs ? abs(diff) : pre_abs;
            if (diff < 0) {
                while (j < k && tmp[j] == tmp[j + 1]) ++j;
                ++j;
            } else if (diff > 0) {
                while (j < k && tmp[k] == tmp[k - 1]) --k;
                --k;
            } else {
                free(tmp);
                return target;
            }
        }
    }
    free(tmp);
    return ret;
}
