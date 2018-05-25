#include "3sum_closest.h"

#include <stdlib.h>
#include <string.h>

static int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int threeSumClosest_16_1(int *nums, int numsSize, int target) {
    if (nums == NULL || numsSize < 3)
        return 0;

    int *values = (int *) malloc(numsSize * sizeof(int));
    memcpy(values, nums, numsSize * sizeof(int));
    qsort(values, numsSize, sizeof(int), compare);

    int ret = values[0] + values[1] + values[2];
    int i, j, k;
    for (i = 0; i < numsSize - 2;) {
        j = i + 1, k = numsSize - 1;
        while (j < k) {
            const int sum = values[i] + values[j] + values[k];
            if (abs(sum - target) < abs(ret - target))
                ret = sum;
            if (sum < target) {
                do { ++j; } while (j < k && values[j] == values[j - 1]);
            } else if (sum > target) {
                do { --k; } while (j < k && values[k] == values[k + 1]);
            } else {
                free(values);
                return ret;
            }
        }
        do { ++i; } while (i < numsSize - 2 && values[i] == values[i - 1]);
    }
    free(values);
    return ret;
}
