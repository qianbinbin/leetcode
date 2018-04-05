#include <minimum-depth-of-binary-tree.h>
#include <stddef.h>

int minDepth_111(struct TreeNode *root) {
    if (root == NULL) return 0;

    int left_depth = minDepth_111(root->left);
    int right_depth = minDepth_111(root->right);
    if (left_depth == 0) return right_depth + 1;
    else if (right_depth == 0) return left_depth + 1;
    else return (left_depth < right_depth ? left_depth : right_depth) + 1;
}
