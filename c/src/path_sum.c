#include "path_sum.h"

#include <stddef.h>

bool hasPathSum_112_1(struct TreeNode *root, int targetSum) {
    if (root == NULL)
        return false;
    if (root->left == NULL && root->right == NULL)
        return root->val == targetSum;
    return hasPathSum_112_1(root->left, targetSum - root->val) ||
           hasPathSum_112_1(root->right, targetSum - root->val);
}
