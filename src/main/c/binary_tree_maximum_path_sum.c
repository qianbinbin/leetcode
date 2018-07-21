#include "binary_tree_maximum_path_sum.h"

#include <stddef.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

static int max_single_path_sum(struct TreeNode *root, int *max_sum) {
    if (root == NULL) return 0;

    int left = max_single_path_sum(root->left, max_sum);
    left = MAX(left, 0);
    int right = max_single_path_sum(root->right, max_sum);
    right = MAX(right, 0);

    *max_sum = MAX(*max_sum, root->val + left + right);

    return MAX(left, right) + root->val;
}

int maxPathSum_124_1(struct TreeNode *root) {
    int ret = root->val;
    max_single_path_sum(root, &ret);
    return ret;
}
