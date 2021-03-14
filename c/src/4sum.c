#include "4sum.h"

#include <stdlib.h>

static int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int **fourSum_18_1(int *nums, int numsSize, int target, int *returnSize,
                   int **returnColumnSizes) {
    int capacity = 16;
    *returnSize = 0;
    int **result = (int **) malloc(capacity * sizeof(int *));
    *returnColumnSizes = (int *) malloc(capacity * sizeof(int));
    if (numsSize < 4)
        goto ret;

    qsort(nums, numsSize, sizeof(int), compare);

    for (int i1 = 0, i2, i3, i4, sum; i1 < numsSize - 3;) {
        for (i2 = i1 + 1; i2 < numsSize - 2;) {
            i3 = i2 + 1;
            i4 = numsSize - 1;
            sum = target - nums[i1] - nums[i2];
            while (i3 < i4) {
                if (nums[i3] + nums[i4] < sum) {
                    do { ++i3; } while (i3 < i4 && nums[i3] == nums[i3 - 1]);
                } else if (nums[i3] + nums[i4] > sum) {
                    do { --i4; } while (i3 < i4 && nums[i4] == nums[i4 + 1]);
                } else {
                    int *quadruplet = (int *) malloc(4 * sizeof(int));
                    quadruplet[0] = nums[i1];
                    quadruplet[1] = nums[i2];
                    quadruplet[2] = nums[i3];
                    quadruplet[3] = nums[i4];
                    if (*returnSize >= capacity) {
                        capacity *= 2;
                        result = (int **) realloc(result,
                                                  capacity * sizeof(int *));
                        *returnColumnSizes = (int *) realloc(*returnColumnSizes,
                                                             capacity *
                                                             sizeof(int));
                    }
                    result[*returnSize] = quadruplet;
                    (*returnColumnSizes)[*returnSize] = 4;
                    ++*returnSize;
                    do { ++i3; } while (i3 < i4 && nums[i3] == nums[i3 - 1]);
                    do { --i4; } while (i3 < i4 && nums[i4] == nums[i4 + 1]);
                }
            }
            do { ++i2; } while (i2 < numsSize - 2 && nums[i2] == nums[i2 - 1]);
        }
        do { ++i1; } while (i1 < numsSize - 3 && nums[i1] == nums[i1 - 1]);
    }
    ret:
    result = realloc(result, (*returnSize) * sizeof(int *));
    return result;
}
