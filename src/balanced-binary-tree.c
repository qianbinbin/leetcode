#include <balanced-binary-tree.h>
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
