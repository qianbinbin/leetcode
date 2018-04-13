#include <permutations-ii.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

static void permute_unique_dfs(int *nums, int nums_size, int **permutations, int *p_size,
                               int *path, int *path_size, bool *used) {
    if (*path_size == nums_size) {
        permutations[*p_size] = (int *) malloc((*path_size) * sizeof(int));
        memcpy(permutations[*p_size], path, (*path_size) * sizeof(int));
        ++(*p_size);
        return;
    }
    for (int i = 0; i < nums_size; ++i) {
        if (used[i]) continue;
        if (i != 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
        path[(*path_size)++] = nums[i];
        used[i] = true;
        permute_unique_dfs(nums, nums_size, permutations, p_size, path, path_size, used);
        --(*path_size);
        used[i] = false;
    }
}

static int factorial(int n) {
    int ret = 1;
    for (int i = 1; i <= n; ++i)
        ret *= i;
    return ret;
}

int **permuteUnique_47(int *nums, int numsSize, int *returnSize) {
    if (nums == NULL || numsSize < 0 || returnSize == NULL) return NULL;

    qsort(nums, numsSize, sizeof(int), compare);

    int capacity = factorial(numsSize);
    int **ret = (int **) malloc(capacity * sizeof(int *));
    *returnSize = 0;

    int *path = (int *) malloc(capacity * sizeof(int));
    int path_size = 0;
    bool *used = (bool *) malloc(numsSize * sizeof(bool));
    memset(used, 0, numsSize * sizeof(bool));

    permute_unique_dfs(nums, numsSize, ret, returnSize, path, &path_size, used);

    free(path);
    free(used);
    ret = (int **) realloc(ret, (*returnSize) * sizeof(int *));
    return ret;
}
