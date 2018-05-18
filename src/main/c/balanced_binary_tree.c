#include <balanced_binary_tree.h>
#include <stdlib.h>

static int tree_depth(struct TreeNode *root) {
    if (root == NULL) return 0;
    int depth_left = tree_depth(root->left) + 1;
    int depth_right = tree_depth(root->right) + 1;
    return depth_left > depth_right ? depth_left : depth_right;
}

bool isBalanced_110_1(struct TreeNode *root) {
    if (root == NULL) return true;
    int depth_diff = abs(tree_depth(root->left) - tree_depth(root->right));
    return depth_diff <= 1 && isBalanced_110_1(root->left) && isBalanced_110_1(root->right);
}

/**
 * If the tree is balanced return its depth, otherwise return -1.
 */
static int balancced_depth(struct TreeNode *root) {
    if (root == NULL) return 0;

    int bdepth_l = balancced_depth(root->left);
    if (bdepth_l == -1) return -1;

    int bdepth_r = balancced_depth(root->right);
    if (bdepth_r == -1) return -1;

    int depth_diff = abs(bdepth_l - bdepth_r);
    if (depth_diff > 1) return -1;

    return (bdepth_l > bdepth_r ? bdepth_l : bdepth_r) + 1;
}

bool isBalanced_110_2(struct TreeNode *root) {
    return balancced_depth(root) >= 0;
}
