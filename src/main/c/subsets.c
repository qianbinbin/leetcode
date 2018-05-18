#include <subsets.h>
#include <stdlib.h>
#include <string.h>

static void subsets(int *nums, int nums_size, int begin,
                    int **sets, int *sets_size, int *col_sizes, int *path, int *path_size) {
    sets[*sets_size] = malloc((*path_size) * sizeof(int));
    memcpy(sets[*sets_size], path, (*path_size) * sizeof(int));
    col_sizes[*sets_size] = *path_size;
    ++(*sets_size);
    for (int i = begin; i < nums_size; ++i) {
        path[(*path_size)++] = nums[i];
        subsets(nums, nums_size, i + 1, sets, sets_size, col_sizes, path, path_size);
        --(*path_size);
    }
}

int **subsets_78(int *nums, int numsSize, int **columnSizes, int *returnSize) {
    if (nums == NULL || numsSize < 0 || columnSizes == NULL || returnSize == NULL) return NULL;

    *returnSize = 1 << numsSize;
    *columnSizes = (int *) malloc((*returnSize) * sizeof(int));
    int **ret = (int **) malloc((*returnSize) * sizeof(int *));
    int size = 0;

    int *path = (int *) malloc(numsSize * sizeof(int));
    int path_size = 0;
    subsets(nums, numsSize, 0, ret, &size, *columnSizes, path, &path_size);
    free(path);
    return ret;
}
