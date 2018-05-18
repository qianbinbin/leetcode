#include <permutations.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static bool value_in_array(int *array, int size, int value) {
    for (int i = 0; i < size; ++i)
        if (array[i] == value) return true;
    return false;
}

static void permute_dfs(int *nums, int nums_size, int index,
                        int **permutations, int *p_size, int *path, int *path_size) {
    if (*path_size == nums_size) {
        permutations[*p_size] = (int *) malloc((*path_size) * sizeof(int));
        memcpy(permutations[*p_size], path, (*path_size) * sizeof(int));
        ++(*p_size);
        return;
    }
    for (int i = 0; i < nums_size; ++i) {
        if (value_in_array(path, *path_size, nums[i])) continue;
        path[(*path_size)++] = nums[i];
        permute_dfs(nums, nums_size, i, permutations, p_size, path, path_size);
        --(*path_size);
    }
}

static int factorial(int n) {
    int ret = 1;
    for (int i = 2; i <= n; ++i)
        ret *= i;
    return ret;
}

int **permute_46(int *nums, int numsSize, int *returnSize) {
    if (nums == NULL || numsSize < 0 || returnSize == NULL) return NULL;

    int capacity = factorial(numsSize);
    int **permutations = (int **) malloc(capacity * sizeof(int *));
    *returnSize = 0;
    int *path = (int *) malloc(capacity * sizeof(int));
    int path_size = 0;

    permute_dfs(nums, numsSize, 0, permutations, returnSize, path, &path_size);

    free(path);
    return permutations;
}
