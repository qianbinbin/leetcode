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

typedef struct {
    int *starts;
    int *ends;
    int size;
    int capacity;
} path;

static path *path_create() {
    path *new = (path *) malloc(sizeof(path));
    new->capacity = 16;
    new->starts = (int *) malloc(new->capacity * sizeof(int));
    new->ends = (int *) malloc(new->capacity * sizeof(int));
    new->size = 0;
    return new;
}

static void path_append(path *p, int start, int end) {
    if (p->size >= p->capacity) {
        p->capacity *= 2;
        p->starts = (int *) realloc(p->starts, p->capacity * sizeof(int));
        p->ends = (int *) realloc(p->ends, p->capacity * sizeof(int));
    }
    p->starts[p->size] = start;
    p->ends[p->size] = end;
    ++p->size;
}

static path *path_new_prepend(path *p, int start, int end) {
    path *new = (path *) malloc(sizeof(path));
    if (p->size >= p->capacity)
        new->capacity = 2 * p->capacity;
    else
        new->capacity = p->capacity;
    new->starts = (int *) malloc(new->capacity * sizeof(int));
    new->ends = (int *) malloc(new->capacity * sizeof(int));
    memcpy(new->starts + 1, p->starts, p->size * sizeof(int));
    memcpy(new->ends + 1, p->ends, p->size * sizeof(int));
    new->starts[0] = start;
    new->ends[0] = end;
    new->size = p->size + 1;
    return new;
}

static void path_free(path *p) {
    free(p->starts);
    free(p->ends);
    free(p);
}

typedef struct {
    void **data;
    int size;
    int capacity;
} array;

static array *array_create() {
    array *new = (array *) malloc(sizeof(array));
    new->capacity = 16;
    new->data = (void **) malloc(new->capacity * sizeof(void *));
    new->size = 0;
    return new;
}

static void array_append(array *arr, void *p) {
    if (arr->size >= arr->capacity) {
        arr->capacity *= 2;
        arr->data = (void **) realloc(arr->data, arr->capacity * sizeof(void *));
    }
    arr->data[arr->size++] = p;
}

static void array_free(array *arr) {
    free(arr->data);
    free(arr);
}

char ***partition_131_2(char *s, int **columnSizes, int *returnSize) {
    if (s == NULL || columnSizes == NULL || returnSize == NULL) return NULL;

    const int len = strlen(s);
    bool **dp = (bool **) malloc(len * sizeof(bool *));
    for (int i = 0; i < len; ++i)
        dp[i] = (bool *) calloc(len, sizeof(bool));

    array **paths_array = (array **) malloc(len * sizeof(array *));
    for (int i = 0; i < len; ++i)
        paths_array[i] = array_create();

    for (int i = len - 1; i >= 0; --i) {
        for (int j = i; j < len; ++j) {
            if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) {
                dp[i][j] = true;
                if (j == len - 1) {
                    path *p = path_create();
                    path_append(p, i, j);
                    array_append(paths_array[i], p);
                } else {
                    path **next_paths = (path **) paths_array[j + 1]->data;
                    const int size = paths_array[j + 1]->size;
                    for (int k = 0; k < size; ++k) {
                        array_append(paths_array[i], path_new_prepend(next_paths[k], i, j));
                    }
                }
            }
        }
    }
    for (int i = 0; i < len; ++i)
        free(dp[i]);
    free(dp);

    *returnSize = paths_array[0]->size;
    *columnSizes = (int *) malloc((*returnSize) * sizeof(int));
    char ***ret = (char ***) malloc((*returnSize) * sizeof(char **));
    for (int i = 0; i < *returnSize; ++i) {
        path *p = paths_array[0]->data[i];
        (*columnSizes)[i] = p->size;
        char **str_path = (char **) malloc(p->size * sizeof(char *));
        for (int j = 0; j < p->size; ++j) {
            str_path[j] = new_string(s, p->starts[j], p->ends[j]);
        }
        ret[i] = str_path;
    }

    for (int i = 0; i < len; ++i) {
        path **paths = (path **) paths_array[i]->data;
        for (int j = 0; j < paths_array[i]->size; ++j) {
            path_free(paths[j]);
        }
        array_free(paths_array[i]);
    }
    free(paths_array);

    return ret;
}
