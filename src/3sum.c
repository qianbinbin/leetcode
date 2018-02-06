#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <3sum.h>

int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int **threeSum_15(int *nums, int numsSize, int *returnSize) {
    if (nums == NULL || numsSize < 3) return NULL;

    int *tmp = (int *) malloc(numsSize * sizeof(int));
    assert(tmp != NULL);
    memcpy(tmp, nums, numsSize * sizeof(int));
    qsort(tmp, numsSize, sizeof(int), compare);

    int max = numsSize * (numsSize - 1) * (numsSize - 2) / 6;
    int **result = (int **) malloc(max * sizeof(int *));
    assert(result != NULL);
    int count = 0;
    int sum;
    int i, j, k;
    for (i = 0; i < numsSize - 2; ++i) {
        while (0 < i && i < numsSize - 2 && tmp[i] == tmp[i - 1]) ++i;
        j = i + 1, k = numsSize - 1;
        while (j < k) {
            sum = tmp[i] + tmp[j] + tmp[k];
            if (sum < 0) {
                while (j < k && tmp[j] == tmp[j + 1]) ++j;
                ++j;
            } else if (sum > 0) {
                while (j < k && tmp[k] == tmp[k - 1]) --k;
                --k;
            } else {
                int *triplet = (int *) malloc(3 * sizeof(int));
                assert(triplet != NULL);
                triplet[0] = tmp[i];
                triplet[1] = tmp[j];
                triplet[2] = tmp[k];
                result[count++] = triplet;
                while (j < k && tmp[j] == tmp[j + 1]) ++j;
                ++j;
                while (j < k && tmp[k] == tmp[k - 1]) --k;
                --k;
            }
        }
    }
    free(tmp);
    if (count > 0) {
        *returnSize = count;
        result = realloc(result, count * sizeof(int *));
        assert(result != NULL);
        return result;
    }
    free(result);
    return NULL;
}