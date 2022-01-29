#include "subsets_ii.h"

#include <stdlib.h>
#include <string.h>

static int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

static void subset_dfs(int *nums, int nums_size, int i,
                       int **sets, int *sets_size, int *col_sizes, int *path,
                       int *path_size) {
    sets[*sets_size] = (int *) malloc((*path_size) * sizeof(int));
    memcpy(sets[*sets_size], path, (*path_size) * sizeof(int));
    col_sizes[*sets_size] = *path_size;
    ++(*sets_size);
    while (i < nums_size) {
        path[(*path_size)++] = nums[i];
        subset_dfs(nums, nums_size, i + 1, sets, sets_size, col_sizes, path,
                   path_size);
        --(*path_size);
        do { ++i; }
        while (i < nums_size && nums[i] == nums[i - 1]);
    }
}

int **subsetsWithDup_90_1(int *nums, int numsSize, int *returnSize,
                          int **returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);

    const int capacity = 1 << numsSize;
    int **ret = (int **) malloc(capacity * sizeof(int *));
    *returnSize = 0;

    *returnColumnSizes = (int *) malloc(capacity * sizeof(int));

    int *path = (int *) malloc(numsSize * sizeof(int));
    int path_size = 0;

    subset_dfs(nums, numsSize, 0, ret, returnSize, *returnColumnSizes, path,
               &path_size);

    ret = (int **) realloc(ret, (*returnSize) * sizeof(int *));
    *returnColumnSizes = (int *) realloc(*returnColumnSizes,
                                         (*returnSize) * sizeof(int));
    free(path);
    return ret;
}
