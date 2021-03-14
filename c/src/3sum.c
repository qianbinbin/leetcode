#include "3sum.h"

#include <stdlib.h>

static int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int **threeSum_15_1(int *nums, int numsSize, int *returnSize,
                    int **returnColumnSizes) {
    int capacity = 16;
    int **set = (int **) malloc(capacity * sizeof(int *));
    *returnColumnSizes = (int *) malloc(capacity * sizeof(int));
    *returnSize = 0;

    if (numsSize < 3)
        goto ret;

    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0, j, k, e = numsSize - 2, sum; i < e;) {
        sum = 0 - nums[i];
        j = i + 1;
        k = numsSize - 1;
        while (j < k) {
            if (nums[j] + nums[k] < sum) {
                do { ++j; } while (j < k && nums[j] == nums[j - 1]);
            } else if (nums[j] + nums[k] > sum) {
                do { --k; } while (j < k && nums[k] == nums[k + 1]);
            } else {
                int *triplet = (int *) malloc(3 * sizeof(int));
                triplet[0] = nums[i];
                triplet[1] = nums[j];
                triplet[2] = nums[k];
                if (*returnSize >= capacity) {
                    capacity <<= 1;
                    set = (int **) realloc(set, capacity * sizeof(int *));
                    *returnColumnSizes = (int *) realloc(*returnColumnSizes,
                                                         capacity *
                                                         sizeof(int));
                }
                set[*returnSize] = triplet;
                (*returnColumnSizes)[(*returnSize)++] = 3;
                do { ++j; } while (j < k && nums[j] == nums[j - 1]);
                do { --k; } while (j < k && nums[k] == nums[k + 1]);
            }
        }
        do { ++i; } while (i < e && nums[i] == nums[i - 1]);
    }

    ret:
    set = realloc(set, (*returnSize) * sizeof(int *));
    *returnColumnSizes = realloc(*returnColumnSizes,
                                 (*returnSize) * sizeof(int));
    return set;
}