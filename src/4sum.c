#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <4sum.h>

int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int **fourSum_18(int *nums, int numsSize, int target, int *returnSize) {
    if (nums == NULL || numsSize < 4) return NULL;
    int *tmp = (int *) malloc(numsSize * sizeof(int));
    assert(tmp != NULL);
    memcpy(tmp, nums, numsSize * sizeof(int));
    qsort(tmp, numsSize, sizeof(int), compare);

    int max = numsSize * (numsSize - 1) * (numsSize - 2) * (numsSize - 3) / 24;
    int **ret = (int **) malloc(max * sizeof(int *));
    assert(ret != NULL);

    int sum;
    int count = 0;
    int i, j, m, n;
    for (i = 0; i < numsSize - 3; ++i) {
        while (0 < i && i < numsSize - 3 && tmp[i] == tmp[i - 1]) ++i;
        for (j = i + 1; j < numsSize - 2; ++j) {
            while (i + 1 < j && j < numsSize - 2 && tmp[j] == tmp[j - 1]) ++j;
            m = j + 1;
            n = numsSize - 1;
            while (m < n) {
                sum = tmp[i] + tmp[j] + tmp[m] + tmp[n];
                if (sum < target) {
                    while (m < n && tmp[m] == tmp[m + 1]) ++m;
                    ++m;
                } else if (sum > target) {
                    while (m < n && tmp[n] == tmp[n - 1]) --n;
                    --n;
                } else {
                    int *quadruplet = (int *) malloc(4 * sizeof(int));
                    assert(quadruplet != NULL);
                    quadruplet[0] = tmp[i];
                    quadruplet[1] = tmp[j];
                    quadruplet[2] = tmp[m];
                    quadruplet[3] = tmp[n];
                    ret[count++] = quadruplet;
                    while (m < n && tmp[m] == tmp[m + 1]) ++m;
                    ++m;
                    while (m < n && tmp[n] == tmp[n - 1]) --n;
                    --n;
                }
            }
        }
    }
    free(tmp);

    if (count > 0) {
        *returnSize = count;
        ret = realloc(ret, count * sizeof(int *));
        assert(ret != NULL);
        return ret;
    }
    return NULL;
}
