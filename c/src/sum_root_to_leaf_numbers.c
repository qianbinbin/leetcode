#include "sum_root_to_leaf_numbers.h"

#include <stddef.h>

static int sum_numbers(struct TreeNode *root, int path) {
    if (root == NULL)
        return 0;
    path = path * 10 + root->val;
    if (root->left == NULL && root->right == NULL) {
        return path;
    }
    return sum_numbers(root->left, path) +
           sum_numbers(root->right, path);
}

int sumNumbers_129_1(struct TreeNode *root) {
    return sum_numbers(root, 0);
}
