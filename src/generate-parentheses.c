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

char **generateParenthesis_22_2(int n, int *returnSize) {
    if (n < 0 || returnSize == NULL) return NULL;

    char **ret = NULL;
    if (n == 0) {
        ret = (char **) malloc(1 * sizeof(char *));
        ret[0] = (char *) malloc(1);
        ret[0][0] = '\0';
        *returnSize = 1;
        return ret;
    }
    if (n == 1) {
        ret = (char **) malloc(1 * sizeof(char *));
        ret[0] = (char *) malloc(3);
        ret[0][0] = '(';
        ret[0][1] = ')';
        ret[0][2] = '\0';
        *returnSize = 1;
        return ret;
    }

    int capacity = 64;
    ret = (char **) malloc(capacity * sizeof(char *));
    *returnSize = 0;

    int outer_size = 0, inner_size = 0;
    for (int i = 0; i < n; ++i) {
        char **outers = generateParenthesis_22_2(i, &outer_size);
        char **inners = generateParenthesis_22_2(n - 1 - i, &inner_size);
        for (int j = 0; j < outer_size; ++j) {
            for (int k = 0; k < inner_size; ++k) {
                if (*returnSize >= capacity) {
                    capacity *= 2;
                    ret = (char **) realloc(ret, capacity * sizeof(char *));
                }
                ret[*returnSize] = (char *) malloc(2 * n + 1);
                memcpy(ret[*returnSize], outers[j], 2 * i);
                ret[*returnSize][2 * i] = '(';
                memcpy(ret[*returnSize] + 2 * i + 1, inners[k], 2 * (n - 1 - i));
                ret[*returnSize][2 * n - 1] = ')';
                ret[*returnSize][2 * n] = '\0';
                ++(*returnSize);
            }
        }
        for (int j = 0; j < outer_size; ++j)
            free(outers[j]);
        free(outers);
        for (int j = 0; j < inner_size; ++j)
            free(inners[j]);
        free(inners);
    }
    ret = (char **) realloc(ret, *returnSize * sizeof(char *));
    return ret;
}
