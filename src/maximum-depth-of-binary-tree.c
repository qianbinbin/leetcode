#include <maximum-depth-of-binary-tree.h>
#include <stddef.h>

int maxDepth_104(struct TreeNode *root) {
    if (root == NULL) return 0;
    int left_depth = maxDepth_104(root->left);
    int right_depth = maxDepth_104(root->right);
    return (left_depth > right_depth ? left_depth : right_depth) + 1;
}
