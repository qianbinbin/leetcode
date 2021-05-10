#include "combination_sum_ii.h"

#include <stdlib.h>
#include <string.h>

static void
combination_sum_dfs(int *sorted_candidates, int c_size, int index, int target,
                    int sum,
                    int ***combinations, int *capacity, int *size,
                    int **col_sizes,
                    int **path, int *path_capacity, int *path_size) {
    if (sum == target) {
        int *new_comb = (int *) malloc(*path_size * sizeof(int));
        memcpy(new_comb, *path, *path_size * sizeof(int));
        if (*size > *capacity) {
            *capacity *= 2;
            *combinations = (int **) realloc(*combinations,
                                             *capacity * sizeof(int *));
            *col_sizes = (int *) realloc(*col_sizes, *capacity * sizeof(int));
        }
        (*combinations)[*size] = new_comb;
        (*col_sizes)[*size] = *path_size;
        ++(*size);
        return;
    }
    for (int prev = -1, val; index < c_size; ++index) {
        val = sorted_candidates[index];
        if (sum + val > target) break;
        if (val == prev) continue;
        prev = val;
        if (*path_size >= *path_capacity) {
            *path_capacity *= 2;
            *path = (int *) realloc(*path, *path_capacity * sizeof(int));
        }
        (*path)[(*path_size)++] = val;
        combination_sum_dfs(sorted_candidates, c_size, index + 1, target,
                            sum + val, combinations, capacity, size, col_sizes,
                            path, path_capacity, path_size);
        --(*path_size);
    }
}

static int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int **combinationSum2_40_1(int *candidates, int candidatesSize, int target,
                           int *returnSize, int **returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), compare);

    int capacity = 64;
    int **ret = (int **) malloc(capacity * sizeof(int *));
    *returnSize = 0;
    *returnColumnSizes = (int *) malloc(capacity * sizeof(int));

    int path_capacity = 64;
    int *path = (int *) malloc(path_capacity * sizeof(int));
    int path_size = 0;

    combination_sum_dfs(candidates, candidatesSize, 0, target, 0,
                        &ret, &capacity, returnSize, returnColumnSizes,
                        &path, &path_capacity, &path_size);

    free(path);

    ret = (int **) realloc(ret, *returnSize * sizeof(int *));
    *returnColumnSizes = (int *) realloc(*returnColumnSizes,
                                         *returnSize * sizeof(int));
    return ret;
}
