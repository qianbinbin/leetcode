#include <palindrome-partitioning.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static bool palindrome(const char *str, int start, int end) {
    const char *src = str + start;
    const int len = end - start + 1;
    const int mid = len / 2;
    for (int i = 0; i <= mid; ++i) {
        if (src[i] != src[len - 1 - i])
            return false;
    }
    return true;
}

static char *new_string(const char *str, int start, int end) {
    const char *src = str + start;
    const len = end - start + 1;
    char *ret = (char *) malloc(len + 1);
    memcpy(ret, src, len);
    ret[len] = '\0';
    return ret;
}

static char *new_str(const char *str) {
    return new_string(str, 0, strlen(str) - 1);
}

static void partition_dfs(char *str, int start, int end,
                          char ****results, int *results_size, int *capacity, int **col_sizes, char **path,
                          int *path_size) {
    if (start > end) {
        if (*results_size >= *capacity) {
            *capacity *= 2;
            *results = (char ***) realloc(*results, (*capacity) * sizeof(char **));
            *col_sizes = (int *) realloc(*col_sizes, (*capacity) * sizeof(int));
        }
        (*results)[*results_size] = (char **) malloc(*path_size * sizeof(char *));
        for (int i = 0; i < *path_size; ++i) {
            (*results)[*results_size][i] = new_str(path[i]);
        }
        (*col_sizes)[*results_size] = *path_size;
        ++(*results_size);
        return;
    }
    for (int i = start; i <= end; ++i) {
        if (palindrome(str, start, i)) {
            path[(*path_size)++] = new_string(str, start, i);
            partition_dfs(str, i + 1, end, results, results_size, capacity, col_sizes, path, path_size);
            free(path[--(*path_size)]);
        }
    }
}

char ***partition_131_1(char *s, int **columnSizes, int *returnSize) {
    if (s == NULL || columnSizes == NULL || returnSize == NULL) return NULL;

    const int len = strlen(s);
    int capacity = 64;
    *columnSizes = (int *) malloc(capacity * sizeof(int));
    *returnSize = 0;
    char ***ret = (char ***) malloc(capacity * sizeof(char **));
    char **path = (char **) malloc(len * sizeof(char *));
    int path_size = 0;

    partition_dfs(s, 0, len - 1, &ret, returnSize, &capacity, columnSizes, path, &path_size);
    free(path);
    *columnSizes = (int *) realloc(*columnSizes, (*returnSize) * sizeof(int));
    ret = (char ***) realloc(ret, (*returnSize) * sizeof(char **));

    return ret;
}
