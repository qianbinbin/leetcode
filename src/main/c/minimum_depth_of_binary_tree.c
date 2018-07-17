#include "minimum_depth_of_binary_tree.h"

#include <stddef.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minDepth_111_1(struct TreeNode *root) {
    if (root == NULL) return 0;
    if (root->left == NULL) return minDepth_111_1(root->right) + 1;
    if (root->right == NULL) return minDepth_111_1(root->left) + 1;
    int left = minDepth_111_1(root->left), right = minDepth_111_1(root->right);
    return MIN(left, right) + 1;
}
