#include "binary_tree_postorder_traversal.h"

#include <stdlib.h>

static void
post_order_traversal(struct TreeNode *root, int **result, int *size) {
    if (root == NULL) return;
    post_order_traversal(root->left, result, size);
    post_order_traversal(root->right, result, size);
    (*result)[(*size)++] = root->val;
}

int *postorderTraversal_145_1(struct TreeNode *root, int *returnSize) {
    int *ret = (int *) malloc(100 * sizeof(int));
    *returnSize = 0;
    post_order_traversal(root, &ret, returnSize);
    ret = (int *) realloc(ret, *returnSize * sizeof(int));
    return ret;
}

int *postorderTraversal_145_2(struct TreeNode *root, int *returnSize) {
    int *ret = (int *) malloc(100 * sizeof(int));
    *returnSize = 0;

    struct TreeNode **stack = (struct TreeNode **) malloc(
            100 * sizeof(struct TreeNode *));
    int top = -1;

    struct TreeNode *node = root, *parent, *pre = NULL;
    while (top != -1 || node != NULL) {
        if (node != NULL) {
            stack[++top] = node;
            node = node->left;
        } else {
            parent = stack[top];
            if (parent->right != NULL && parent->right != pre) {
                node = parent->right;
            } else {
                ret[(*returnSize)++] = parent->val;
                pre = parent;
                --top;
            }
        }
    }
    free(stack);
    ret = (int *) realloc(ret, *returnSize * sizeof(int));
    return ret;
}

int *postorderTraversal_145_3(struct TreeNode *root, int *returnSize) {
    int *ret = (int *) malloc(100 * sizeof(int));
    *returnSize = 0;

    if (root == NULL) goto ret;

    void **stack = (void **) malloc(100 * sizeof(void *));
    int top = -1;
    stack[++top] = root;
    struct TreeNode *node;
    while (top != -1) {
        node = stack[top--];
        ret[(*returnSize)++] = node->val;
        if (node->left != NULL) stack[++top] = node->left;
        if (node->right != NULL) stack[++top] = node->right;
    }
    free(stack);

    ret:
    ret = (int *) realloc(ret, *returnSize * sizeof(int));
    const int half = *returnSize / 2;
    int tmp;
    for (int i = 0; i < half; ++i) {
        tmp = ret[i];
        ret[i] = ret[*returnSize - i - 1];
        ret[*returnSize - i - 1] = tmp;
    }
    return ret;
}
