#include "4sum.h"

#include <stdlib.h>
#include <string.h>

static int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int **fourSum_18_1(int *nums, int numsSize, int target, int *returnSize) {
    if (nums == NULL || numsSize < 0) return NULL;
    if (numsSize < 4) {
        int **ret = (int **) malloc(0);
        *returnSize = 0;
        return ret;
    }

    int *values = (int *) malloc(numsSize * sizeof(int));
    memcpy(values, nums, numsSize * sizeof(int));
    qsort(values, numsSize, sizeof(int), compare);

    int capacity = numsSize * (numsSize - 1) * (numsSize - 2) * (numsSize - 3) / 24;
    int **ret = (int **) malloc(capacity * sizeof(int *));

    for (int i = 0; i < numsSize - 3;) {
        for (int j = i + 1; j < numsSize - 2;) {
            const int sum = target - values[i] - values[j];
            int m = j + 1;
            int n = numsSize - 1;
            while (m < n) {
                if (values[m] + values[n] < sum) {
                    do { ++m; } while (m < n && values[m] == values[m - 1]);
                } else if (values[m] + values[n] > sum) {
                    do { --n; } while (m < n && values[n] == values[n + 1]);
                } else {
                    int *quadruplet = (int *) malloc(4 * sizeof(int));
                    quadruplet[0] = values[i];
                    quadruplet[1] = values[j];
                    quadruplet[2] = values[m];
                    quadruplet[3] = values[n];
                    ret[(*returnSize)++] = quadruplet;
                    do { ++m; } while (m < n && values[m] == values[m - 1]);
                    do { --n; } while (m < n && values[n] == values[n + 1]);
                }
            }
            do { ++j; } while (j < numsSize - 2 && values[j] == values[j - 1]);
        }
        do { ++i; } while (i < numsSize - 3 && values[i] == values[i - 1]);
    }
    free(values);

    ret = realloc(ret, (*returnSize) * sizeof(int *));
    return ret;
}
