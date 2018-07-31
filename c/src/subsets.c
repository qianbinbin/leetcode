#include "subsets.h"

#include <stdlib.h>
#include <string.h>

static void subsets(int *nums, int nums_size, int index,
                    int **sets, int *sets_size, int *col_sizes, int *path, int *path_size) {
    sets[*sets_size] = (int *) malloc((*path_size) * sizeof(int));
    memcpy(sets[*sets_size], path, (*path_size) * sizeof(int));
    col_sizes[*sets_size] = *path_size;
    ++*sets_size;
    for (int i = index; i < nums_size; ++i) {
        path[(*path_size)++] = nums[i];
        subsets(nums, nums_size, i + 1, sets, sets_size, col_sizes, path, path_size);
        --(*path_size);
    }
}

int **subsets_78_1(int *nums, int numsSize, int **columnSizes, int *returnSize) {
    if (nums == NULL || numsSize < 0 || columnSizes == NULL || returnSize == NULL) return NULL;

    const int capacity = 1 << numsSize;
    *columnSizes = (int *) malloc(capacity * sizeof(int));
    int **ret = (int **) malloc(capacity * sizeof(int *));
    *returnSize = 0;

    int *path = (int *) malloc(numsSize * sizeof(int));
    int path_size = 0;
    subsets(nums, numsSize, 0, ret, returnSize, *columnSizes, path, &path_size);
    free(path);
    return ret;
}
