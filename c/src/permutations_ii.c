#include "permutations_ii.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

static void
permute_unique_dfs(int *nums, int nums_size, bool *visited, int **permutations,
                   int *column_sizes, int *size, int *path, int *path_size) {
    if (*path_size == nums_size) {
        permutations[*size] = (int *) malloc((nums_size) * sizeof(int));
        memcpy(permutations[*size], path, (nums_size) * sizeof(int));
        column_sizes[*size] = nums_size;
        ++(*size);
        return;
    }
    for (int i = 0, last = -1; i < nums_size; ++i) {
        if (visited[i] ||
            (last != -1 && nums[i] == nums[last]))
            continue;
        last = i;
        path[(*path_size)++] = nums[i];
        visited[i] = true;
        permute_unique_dfs(nums, nums_size, visited, permutations,
                           column_sizes, size, path, path_size);
        visited[i] = false;
        --(*path_size);
    }
}

static int factorial(int n) {
    int ret = 1;
    for (int i = 2; i <= n; ++i)
        ret *= i;
    return ret;
}

int **permuteUnique_47_1(int *nums, int numsSize, int *returnSize,
                         int **returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);

    int const capacity = factorial(numsSize);
    int **ret = (int **) malloc(capacity * sizeof(int *));
    *returnColumnSizes = (int *) calloc(capacity, sizeof(int));
    *returnSize = 0;

    int *path = (int *) malloc(numsSize * sizeof(int));
    int path_size = 0;
    bool *visited = (bool *) calloc(numsSize, sizeof(bool));

    permute_unique_dfs(nums, numsSize, visited, ret, *returnColumnSizes,
                       returnSize, path, &path_size);

    free(path);
    free(visited);
    ret = (int **) realloc(ret, (*returnSize) * sizeof(int *));
    *returnColumnSizes = (int *) realloc(*returnColumnSizes,
                                         (*returnSize) * sizeof(int));
    return ret;
}
