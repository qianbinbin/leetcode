#include "binary_tree_inorder_traversal.h"

#include <stdlib.h>

static void
in_order(struct TreeNode *root, int **ret, int *size) {
    if (root == NULL) return;
    in_order(root->left, ret, size);
    (*ret)[(*size)++] = root->val;
    in_order(root->right, ret, size);
}

int *inorderTraversal_94_1(struct TreeNode *root, int *returnSize) {
    int *ret = (int *) malloc(100 * sizeof(int));
    *returnSize = 0;
    in_order(root, &ret, returnSize);
    ret = (int *) realloc(ret, *returnSize * sizeof(int));
    return ret;
}

int *inorderTraversal_94_2(struct TreeNode *root, int *returnSize) {
    int *ret = (int *) malloc(100 * sizeof(int));
    *returnSize = 0;

    struct TreeNode **stack = (struct TreeNode **) malloc(
            100 * sizeof(struct TreeNode *));
    int top = -1;

    struct TreeNode *node = root;
    while (top != -1 || node != NULL) {
        if (node != NULL) {
            stack[++top] = node;
            node = node->left;
        } else {
            node = stack[top--];
            ret[(*returnSize)++] = node->val;
            node = node->right;
        }
    }
    free(stack);
    ret = (int *) realloc(ret, *returnSize * sizeof(int));
    return ret;
}
