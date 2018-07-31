#include "sum_root_to_leaf_numbers.h"

#include <stddef.h>

static void sum_numbers(struct TreeNode *root, int *ret, int path) {
    path = path * 10 + root->val;
    if (root->left == NULL && root->right == NULL) {
        *ret += path;
        return;
    }
    if (root->left != NULL) sum_numbers(root->left, ret, path);
    if (root->right != NULL) sum_numbers(root->right, ret, path);
}

int sumNumbers_129_1(struct TreeNode *root) {
    if (root == NULL) return 0;
    int ret = 0;
    sum_numbers(root, &ret, 0);
    return ret;
}
