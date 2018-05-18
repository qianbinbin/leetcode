#include <path_sum.h>
#include <stddef.h>

bool hasPathSum_112(struct TreeNode *root, int sum) {
    if (root == NULL) return false;
    if (root->left == NULL && root->right == NULL) return sum == root->val;
    return hasPathSum_112(root->left, sum - root->val) || hasPathSum_112(root->right, sum - root->val);
}
