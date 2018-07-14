#include "same_tree.h"

#include <stddef.h>

bool isSameTree_100_1(struct TreeNode *p, struct TreeNode *q) {
    if (p == q) return true;
    if (p == NULL || q == NULL) return p == q;
    return p->val == q->val && isSameTree_100_1(p->left, q->left) && isSameTree_100_1(p->right, q->right);
}
