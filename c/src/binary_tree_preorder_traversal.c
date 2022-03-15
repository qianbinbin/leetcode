#include "binary_tree_preorder_traversal.h"

#include <stdlib.h>

static void
pre_order_traversal(struct TreeNode *root, int **result, int *size) {
    if (root == NULL) return;
    (*result)[(*size)++] = root->val;
    pre_order_traversal(root->left, result, size);
    pre_order_traversal(root->right, result, size);
}

int *preorderTraversal_144_1(struct TreeNode *root, int *returnSize) {
    if (root == NULL) return NULL;

    int *ret = (int *) malloc(100 * sizeof(int));
    *returnSize = 0;

    pre_order_traversal(root, &ret, returnSize);

    ret = (int *) realloc(ret, *returnSize * sizeof(int));
    return ret;
}

int *preorderTraversal_144_2(struct TreeNode *root, int *returnSize) {
    *returnSize = 0;
    int *ret = (int *) malloc(100 * sizeof(int));
    if (root == NULL) goto ret;

    struct TreeNode **stack = (struct TreeNode **) malloc(
            100 * sizeof(struct TreeNode *));
    int top = -1;
    stack[++top] = root;

    struct TreeNode *node;
    while (top != -1) {
        node = stack[top--];
        ret[(*returnSize)++] = node->val;
        if (node->right != NULL) stack[++top] = node->right;
        if (node->left != NULL) stack[++top] = node->left;
    }
    free(stack);
    ret:
    ret = (int *) realloc(ret, *returnSize * sizeof(int));
    return ret;
}
