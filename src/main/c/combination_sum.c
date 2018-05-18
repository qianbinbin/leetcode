#include <combination_sum.h>
#include <stdlib.h>
#include <string.h>

static void combination_sum_dfs(int *candidates, int c_size, int index, int target, int sum,
                                int ***combinations, int *capacity, int *size, int **col_sizes,
                                int **path, int *path_capacity, int *path_size) {
    if (sum == target) {
        int *new_comb = (int *) malloc(*path_size * sizeof(int));
        memcpy(new_comb, *path, *path_size * sizeof(int));
        if (*size > *capacity) {
            *capacity *= 2;
            *combinations = (int **) realloc(*combinations, *capacity * sizeof(int *));
            *col_sizes = (int *) realloc(*col_sizes, *capacity * sizeof(int));
        }
        (*combinations)[*size] = new_comb;
        (*col_sizes)[*size] = *path_size;
        ++(*size);
        return;
    }
    if (sum > target) return;
    for (int i = index; i < c_size; ++i) {
        if (*path_size >= *path_capacity) {
            *path_capacity *= 2;
            *path = (int *) realloc(*path, *path_capacity * sizeof(int));
        }
        (*path)[(*path_size)++] = candidates[i];
        combination_sum_dfs(candidates, c_size, i, target, sum + candidates[i],
                            combinations, capacity, size, col_sizes,
                            path, path_capacity, path_size);
        --(*path_size);
    }
}

int **combinationSum_39(int *candidates, int candidatesSize, int target, int **columnSizes, int *returnSize) {
    if (candidates == NULL || candidatesSize < 1 || target < 1 || columnSizes == NULL || returnSize == NULL)
        return NULL;

    int capacity = 64;
    int **ret = (int **) malloc(capacity * sizeof(int *));
    *returnSize = 0;
    *columnSizes = (int *) malloc(capacity * sizeof(int));

    int path_capacity = 64;
    int *path = (int *) malloc(path_capacity * sizeof(int));
    int path_size = 0;

    combination_sum_dfs(candidates, candidatesSize, 0, target, 0,
                        &ret, &capacity, returnSize, columnSizes,
                        &path, &path_capacity, &path_size);

    free(path);

    ret = (int **) realloc(ret, *returnSize * sizeof(int *));
    *columnSizes = (int *) realloc(*columnSizes, *returnSize * sizeof(int));
    return ret;
}
