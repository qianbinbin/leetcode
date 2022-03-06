#include "palindrome_partitioning.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static void partition_dfs(char *str, int len, int index, bool **palindrome,
                          char ****result, int *size, int *capacity,
                          int **col_sizes, char **path, int *path_size) {
    if (index == len) {
        if (*size >= *capacity) {
            *capacity *= 2;
            *result = (char ***) realloc(*result, *capacity * sizeof(char **));
            *col_sizes = (int *) realloc(*col_sizes, *capacity * sizeof(int));
        }
        char **list = (char **) malloc(*path_size * sizeof(char *));
        for (int i = 0; i < *path_size; ++i)
            list[i] = strdup(path[i]);
        (*result)[*size] = list;
        (*col_sizes)[(*size)++] = *path_size;
        return;
    }
    for (int i = index; i < len; ++i) {
        if (palindrome[index][i]) {
            path[(*path_size)++] = strndup(str + index, i - index + 1);
            partition_dfs(str, len, i + 1, palindrome, result, size, capacity,
                          col_sizes, path, path_size);
            free(path[--*path_size]);
        }
    }
}

char ***partition_131_1(char *s, int *returnSize, int **returnColumnSizes) {
    const int len = (const int) strlen(s);
    bool **dp = (bool **) malloc(len * sizeof(bool *));
    for (int i = 0; i < len; ++i) dp[i] = (bool *) calloc(len, sizeof(bool));

    for (int i = len - 1; i >= 0; --i) {
        dp[i][i] = true;
        if (i + 1 < len && s[i] == s[i + 1]) dp[i][i + 1] = true;
        for (int j = i + 2; j < len; ++j)
            if (s[i] == s[j] && dp[i + 1][j - 1]) dp[i][j] = true;
    }

    int capacity = 16;
    *returnColumnSizes = (int *) malloc(capacity * sizeof(int));
    *returnSize = 0;
    char ***ret = (char ***) malloc(capacity * sizeof(char **));
    char **path = (char **) malloc(len * sizeof(char *));
    int path_size = 0;

    partition_dfs(s, len, 0, dp, &ret, returnSize, &capacity, returnColumnSizes,
                  path, &path_size);
    free(path);
    *returnColumnSizes = (int *) realloc(*returnColumnSizes,
                                         *returnSize * sizeof(int));
    ret = (char ***) realloc(ret, *returnSize * sizeof(char **));
    return ret;
}
