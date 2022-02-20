#include "balanced_binary_tree.h"

#include <stdlib.h>

#define MAX(a, b) ((a) >= (b) ? (a) : (b))

static int depth(struct TreeNode *root) {
    if (root == NULL)
        return 0;
    int left = depth(root->left);
    if (left == -1)
        return -1;
    int right = depth(root->right);
    if (right == -1)
        return -1;
    if (abs(left - right) > 1)
        return -1;
    return MAX(left, right) + 1;
}

bool isBalanced_110_1(struct TreeNode *root) {
    return depth(root) != -1;
}
