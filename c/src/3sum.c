#include "3sum.h"

#include <stdlib.h>
#include <string.h>

static int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int **threeSum_15_1(int *nums, int numsSize, int *returnSize) {
    if (nums == NULL || numsSize < 0) return NULL;
    if (numsSize < 3)
        return (int **) malloc(0);

    int *values = (int *) malloc(numsSize * sizeof(int));
    memcpy(values, nums, numsSize * sizeof(int));
    qsort(values, numsSize, sizeof(int), compare);

    const int capacity = numsSize * (numsSize - 1) * (numsSize - 2) / 6;
    int **ret = (int **) malloc(capacity * sizeof(int *));
    *returnSize = 0;

    int i, j, k;
    for (i = 0; i < numsSize - 2;) {
        const int sum = 0 - values[i];
        j = i + 1, k = numsSize - 1;
        while (j < k) {
            if (values[j] + values[k] < sum) {
                do { ++j; } while (j < k && values[j] == values[j - 1]);
            } else if (values[j] + values[k] > sum) {
                do { --k; } while (j < k && values[k] == values[k + 1]);
            } else {
                int *triplet = (int *) malloc(3 * sizeof(int));
                triplet[0] = values[i];
                triplet[1] = values[j];
                triplet[2] = values[k];
                ret[(*returnSize)++] = triplet;
                do { ++j; } while (j < k && values[j] == values[j - 1]);
                do { --k; } while (j < k && values[k] == values[k + 1]);
            }
        }
        do { ++i; } while (i < numsSize - 2 && values[i] == values[i - 1]);
    }
    free(values);
    ret = realloc(ret, (*returnSize) * sizeof(int *));
    return ret;
}