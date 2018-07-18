#include "path_sum_ii.h"

#include <stdlib.h>
#include <string.h>

static void array_append(int **array, int *size, int *capacity, int val) {
    if (*size >= *capacity) {
        *capacity *= 2;
        *array = (int *) realloc(*array, *capacity * sizeof(int));
    }
    (*array)[(*size)++] = val;
}

static void path_sum(struct TreeNode *root, int **path, int *path_size, int *path_capacity, int sum,
                     int ***return_paths, int **return_sizes, int *return_size, int *return_capacity) {
    array_append(path, path_size, path_capacity, root->val);

    if (root->left == NULL && root->right == NULL) {
        if (root->val == sum) {
            if (*return_size >= *return_capacity) {
                *return_capacity *= 2;
                *return_paths = realloc(*return_paths, *return_capacity * sizeof(int *));
                *return_sizes = realloc(*return_sizes, *return_capacity * sizeof(int));
            }
            int *new_path = (int *) malloc(*path_size * sizeof(int));
            memcpy(new_path, *path, *path_size * sizeof(int));
            (*return_paths)[*return_size] = new_path;
            (*return_sizes)[*return_size] = *path_size;
            ++*return_size;
        }
        --*path_size;
        return;
    }

    if (root->left != NULL)
        path_sum(root->left, path, path_size, path_capacity, sum - root->val,
                 return_paths, return_sizes, return_size, return_capacity);
    if (root->right != NULL)
        path_sum(root->right, path, path_size, path_capacity, sum - root->val,
                 return_paths, return_sizes, return_size, return_capacity);

    --*path_size;
}

int **pathSum_113_1(struct TreeNode *root, int sum, int **columnSizes, int *returnSize) {
    if (root == NULL || columnSizes == NULL || returnSize == NULL) return NULL;

    int path_capacity = 16;
    int *path = (int *) malloc(path_capacity * sizeof(int));
    int path_size = 0;

    int return_capacity = 16;
    *columnSizes = (int *) malloc(return_capacity * sizeof(int));
    *returnSize = 0;
    int **ret = (int **) malloc(return_capacity * sizeof(int *));

    path_sum(root, &path, &path_size, &path_capacity, sum, &ret, columnSizes, returnSize, &return_capacity);

    *columnSizes = (int *) realloc(*columnSizes, *returnSize * sizeof(int));
    ret = (int **) realloc(ret, *returnSize * sizeof(int *));
    free(path);
    return ret;
}
