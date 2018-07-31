#include "balanced_binary_tree.h"

#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

static int depth(struct TreeNode *root, bool *balanced) {
    if (root == NULL) return 0;
    int left = depth(root->left, balanced);
    int right = depth(root->right, balanced);
    if (abs(left - right) > 1)
        *balanced = false;
    return MAX(left, right) + 1;
}

bool isBalanced_110_1(struct TreeNode *root) {
    bool balanced = true;
    depth(root, &balanced);
    return balanced;
}
