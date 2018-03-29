#include <symmetric-tree.h>
#include <stdlib.h>

static bool is_symmetric(struct TreeNode *p, struct TreeNode *q) {
    if (p == q) return true;
    if (p == NULL || q == NULL) return p == q;
    return p->val == q->val && is_symmetric(p->left, q->right) && is_symmetric(p->right, q->left);
}

bool isSymmetric_101_1(struct TreeNode *root) {
    if (root == NULL) return true;
    return is_symmetric(root->left, root->right);
}
