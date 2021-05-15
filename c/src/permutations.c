#include "permutations.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static void permute_dfs(int *nums, int nums_size, bool *visited,
                        int **permutations, int *column_sizes, int *size,
                        int *path, int *path_size) {
    if (*path_size == nums_size) {
        permutations[*size] = (int *) malloc((nums_size) * sizeof(int));
        memcpy(permutations[*size], path, (nums_size) * sizeof(int));
        column_sizes[*size] = nums_size;
        ++(*size);
        return;
    }
    for (int i = 0; i < nums_size; ++i) {
        if (visited[i]) continue;
        path[(*path_size)++] = nums[i];
        visited[i] = true;
        permute_dfs(nums, nums_size, visited, permutations, column_sizes, size,
                    path, path_size);
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

int **permute_46_1(int *nums, int numsSize, int *returnSize,
                   int **returnColumnSizes) {
    int const capacity = factorial(numsSize);
    int **permutations = (int **) malloc(capacity * sizeof(int *));
    *returnColumnSizes = (int *) calloc(capacity, sizeof(int));
    *returnSize = 0;
    int *path = (int *) malloc(numsSize * sizeof(int));
    int path_size = 0;
    bool *visited = (bool *) calloc(numsSize, sizeof(bool));

    permute_dfs(nums, numsSize, visited, permutations, *returnColumnSizes,
                returnSize, path, &path_size);

    free(visited);
    free(path);
    return permutations;
}
