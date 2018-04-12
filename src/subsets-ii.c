#include <subsets-ii.h>
#include <stdlib.h>
#include <string.h>

static int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

static void subset_dfs(int *nums, int nums_size, int begin,
                       int **sets, int *sets_size, int *col_sizes, int *path, int *path_size) {
    sets[*sets_size] = (int *) malloc((*path_size) * sizeof(int));
    memcpy(sets[*sets_size], path, (*path_size) * sizeof(int));
    col_sizes[*sets_size] = *path_size;
    ++(*sets_size);
    for (int i = begin; i < nums_size; ++i) {
        if (i != begin && nums[i] == nums[i - 1]) continue;
        path[(*path_size)++] = nums[i];
        subset_dfs(nums, nums_size, i + 1, sets, sets_size, col_sizes, path, path_size);
        --(*path_size);
    }
}

int **subsetsWithDup_90(int *nums, int numsSize, int **columnSizes, int *returnSize) {
    if (nums == NULL || numsSize < 0 || columnSizes == NULL || returnSize == NULL) return NULL;

    qsort(nums, numsSize, sizeof(int), compare);

    int capacity = 1 << numsSize;
    int **ret = (int **) malloc(capacity * sizeof(int *));
    *returnSize = 0;

    *columnSizes = (int *) malloc(capacity * sizeof(int));

    int *path = (int *) malloc(numsSize * sizeof(int));
    int path_size = 0;

    subset_dfs(nums, numsSize, 0, ret, returnSize, *columnSizes, path, &path_size);

    ret = (int **) realloc(ret, (*returnSize) * sizeof(int *));
    *columnSizes = (int *) realloc(*columnSizes, (*returnSize) * sizeof(int));
    free(path);
    return ret;
}
