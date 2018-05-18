#include <path_sum_ii.h>
#include <stdlib.h>
#include <string.h>

static void array_append(int **array, int *size, int *capacity, int val) {
    if (*size + 1 >= *capacity) {
        (*capacity) *= 2;
        *array = (int *) realloc(*array, (*capacity) * sizeof(int));
    }
    (*array)[(*size)++] = val;
}

static void generate_paths(struct TreeNode *root, int **path, int *path_size, int *path_capacity, int sum,
                           int ***return_paths, int **return_sizes, int *return_size, int *return_capacity) {
    if (root == NULL) return;

    array_append(path, path_size, path_capacity, root->val);

    if (root->left == NULL && root->right == NULL) {
        if (root->val == sum) {
            if (*return_size + 1 >= *return_capacity) {
                (*return_capacity) *= 2;
                *return_paths = realloc(*return_paths, (*return_capacity) * sizeof(int *));
                *return_sizes = realloc(*return_sizes, (*return_capacity) * sizeof(int));
            }
            int *this_path = (int *) malloc((*path_size) * sizeof(int));
            memcpy(this_path, *path, (*path_size) * sizeof(int));
            (*return_paths)[*return_size] = this_path;
            (*return_sizes)[*return_size] = *path_size;
            ++(*return_size);
        }
    }

    generate_paths(root->left, path, path_size, path_capacity, sum - root->val,
                   return_paths, return_sizes, return_size, return_capacity);
    generate_paths(root->right, path, path_size, path_capacity, sum - root->val,
                   return_paths, return_sizes, return_size, return_capacity);

    --(*path_size);
}

int **pathSum_113(struct TreeNode *root, int sum, int **columnSizes, int *returnSize) {
    if (root == NULL || columnSizes == NULL || returnSize == NULL) return NULL;

    int path_capacity = 64;
    int *path = (int *) malloc(path_capacity * sizeof(int));
    int path_size = 0;

    int return_capacity = 64;
    *columnSizes = (int *) malloc(return_capacity * sizeof(int));
    *returnSize = 0;
    int **ret_paths = (int **) malloc(return_capacity * sizeof(int *));

    generate_paths(root, &path, &path_size, &path_capacity, sum, &ret_paths, columnSizes, returnSize, &return_capacity);
    *columnSizes = (int *) realloc(*columnSizes, (*returnSize) * sizeof(int));
    ret_paths = (int **) realloc(ret_paths, (*returnSize) * sizeof(int *));
    free(path);
    return ret_paths;
}
