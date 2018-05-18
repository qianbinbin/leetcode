#include <binary_tree_zigzag_level_order_traversal.h>
#include <stdlib.h>
#include <string.h>

int tree_depth(struct TreeNode *root) {
    if (root == NULL) return 0;

    int depth_left = tree_depth(root->left) + 1;
    int depth_right = tree_depth(root->right) + 1;
    return depth_left > depth_right ? depth_left : depth_right;
}

void append_array(int **array, int *size, int *capacity, int value) {
    if (*size >= *capacity) {
        *capacity *= 2;
        *array = realloc(*array, (*capacity) * sizeof(int));
    }
    (*array)[(*size)++] = value;
}

void prepend_array(int **array, int *size, int *capacity, int value) {
    if (*size >= *capacity) {
        *capacity *= 2;
        *array = realloc(*array, (*capacity) * sizeof(int));
    }
    memmove(*array + 1, *array, (*size) * sizeof(int));
    (*array)[0] = value;
    ++(*size);
}

void resize_array(int **arrays, int size, const int *columnSizes) {
    for (int i = 0; i < size; ++i) {
        arrays[i] = realloc(arrays[i], columnSizes[i] * sizeof(int));
    }
}

void traverse_zigzag(struct TreeNode *root, int **values, int level, int *sizes, int *capacities) {
    if (root == NULL) return;

    if (level % 2 == 0) {
        append_array(&values[level], &sizes[level], &capacities[level], root->val);
    } else {
        prepend_array(&values[level], &sizes[level], &capacities[level], root->val);
    }
    traverse_zigzag(root->left, values, level + 1, sizes, capacities);
    traverse_zigzag(root->right, values, level + 1, sizes, capacities);
}

int **zigzagLevelOrder_103(struct TreeNode *root, int **columnSizes, int *returnSize) {
    if (root == NULL || columnSizes == NULL || returnSize == NULL) return NULL;

    *returnSize = tree_depth(root);
    *columnSizes = (int *) malloc(*returnSize * sizeof(int));
    int *capacities = malloc(*returnSize * sizeof(int));
    int **ret = (int **) malloc(*returnSize * sizeof(int *));
    for (int i = 0; i < *returnSize; ++i) {
        (*columnSizes)[i] = 0;
        capacities[i] = 64;
        ret[i] = (int *) malloc(64 * sizeof(int));
    }

    traverse_zigzag(root, ret, 0, *columnSizes, capacities);
    resize_array(ret, *returnSize, *columnSizes);
    return ret;
}
