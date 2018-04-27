#include <generate-parentheses.h>
#include <stdlib.h>
#include <string.h>

static void gen_parenthesis_dfs(int n, int depth, char ***parenthesis, int *capacity, int *size,
                                char *path, int path_size, int top) {
    if (depth == 2 * n) {
        if (top == -1) {
            if (*size >= *capacity) {
                *capacity *= 2;
                *parenthesis = (char **) realloc(*parenthesis, *capacity * sizeof(char *));
            }
            (*parenthesis)[*size] = (char *) malloc(2 * n + 1);
            strcpy((*parenthesis)[*size], path);
            ++(*size);
        }
        return;
    }
    if (top < n - 1) {
        path[path_size] = '(';
        gen_parenthesis_dfs(n, depth + 1, parenthesis, capacity, size, path, path_size + 1, top + 1);
    }
    if (top > -1) {
        path[path_size] = ')';
        gen_parenthesis_dfs(n, depth + 1, parenthesis, capacity, size, path, path_size + 1, top - 1);
    }
}

char **generateParenthesis_22_1(int n, int *returnSize) {
    if (n < 0 || returnSize == NULL) return NULL;

    int capacity = 64;
    char **ret = (char **) malloc(capacity * sizeof(char *));
    *returnSize = 0;

    char *path = (char *) malloc(2 * n + 1);
    path[2 * n] = '\0';

    gen_parenthesis_dfs(n, 0, &ret, &capacity, returnSize, path, 0, -1);

    ret = (char **) realloc(ret, *returnSize * sizeof(char *));
    return ret;
}
