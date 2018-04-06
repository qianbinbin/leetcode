#include <sum-root-to-leaf-numbers.h>
#include <stddef.h>

static int path_sum(struct TreeNode *root, int sum) {
    if (root == NULL) return 0;

    sum = sum * 10 + root->val;
    if (root->left == NULL && root->right == NULL)
        return sum;
    else return path_sum(root->left, sum) + path_sum(root->right, sum);
}

int sumNumbers_129(struct TreeNode *root) {
    return path_sum(root, 0);
}
