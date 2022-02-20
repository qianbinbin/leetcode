#include "minimum_depth_of_binary_tree.h"

#include <stddef.h>

#define MIN(a, b) ((a) <= (b) ? (a) : (b))

int minDepth_111_1(struct TreeNode *root) {
    if (root == NULL) return 0;
    int left = minDepth_111_1(root->left), right = minDepth_111_1(root->right);
    if (left == 0)
        return right + 1;
    if (right == 0)
        return left + 1;
    return MIN(left, right) + 1;
}

int minDepth_111_2(struct TreeNode *root) {
    // TODO: BFS
}