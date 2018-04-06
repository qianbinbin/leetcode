#include <binary-tree-maximum-path-sum.h>
#include <stddef.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

static int max_single_path(struct TreeNode *root, int *max_sum) {
    if (root == NULL) return 0;

    int left_single_path = max_single_path(root->left, max_sum);
    int right_single_path = max_single_path(root->right, max_sum);

    int max_path = root->val;
    if (left_single_path > 0) max_path += left_single_path;
    if (right_single_path > 0) max_path += right_single_path;
    *max_sum = MAX(*max_sum, max_path);

    int max_single_path = MAX(left_single_path, right_single_path);
    if (max_single_path > 0) return max_single_path + root->val;
    else return root->val;
}

int maxPathSum_124(struct TreeNode *root) {
    int ret = INT_MIN;
    max_single_path(root, &ret);
    return ret;
}
