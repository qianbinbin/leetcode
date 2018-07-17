#include "path_sum.h"

#include <stddef.h>

static bool has_path_sum(struct TreeNode *root, int sum) {
    if (root == NULL) return sum == 0;
    if (root->left == NULL) return has_path_sum(root->right, sum - root->val);
    if (root->right == NULL) return has_path_sum(root->left, sum - root->val);
    return has_path_sum(root->left, sum - root->val) || has_path_sum(root->right, sum - root->val);
}

bool hasPathSum_112_1(struct TreeNode *root, int sum) {
    if (root == NULL) return false; // dirty case
    return has_path_sum(root, sum);
}
