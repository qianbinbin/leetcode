#include "binary_tree_preorder_traversal.h"

#include <stdlib.h>

static void pre_order_traversal(struct TreeNode *root, int **result, int *capacity, int *size) {
    if (root == NULL) return;
    if (*size >= *capacity) {
        *capacity *= 2;
        *result = (int *) realloc(*result, *capacity * sizeof(int));
    }
    (*result)[(*size)++] = root->val;
    pre_order_traversal(root->left, result, capacity, size);
    pre_order_traversal(root->right, result, capacity, size);
}

int *preorderTraversal_144_1(struct TreeNode *root, int *returnSize) {
    if (root == NULL || returnSize == NULL) return NULL;

    int capacity = 16;
    int *ret = (int *) malloc(capacity * sizeof(int));
    *returnSize = 0;

    pre_order_traversal(root, &ret, &capacity, returnSize);

    ret = (int *) realloc(ret, *returnSize * sizeof(int));
    return ret;
}

int *preorderTraversal_144_2(struct TreeNode *root, int *returnSize) {
    if (root == NULL || returnSize == NULL) return NULL;

    int capacity = 16;
    *returnSize = 0;
    int *ret = (int *) malloc(capacity * sizeof(int));

    int stack_capacity = 16;
    struct TreeNode **stack = (struct TreeNode **) malloc(stack_capacity * sizeof(struct TreeNode *));
    int top = -1;
    stack[++top] = root;

    struct TreeNode *p;
    while (top != -1) {
        p = stack[top--];
        if (*returnSize == capacity) {
            capacity *= 2;
            ret = (int *) realloc(ret, capacity * sizeof(int));
        }
        ret[(*returnSize)++] = p->val;

        if (top + 1 + 2 >= stack_capacity) {
            stack_capacity *= 2;
            stack = (struct TreeNode **) realloc(stack, stack_capacity * sizeof(struct TreeNode *));
        }

        if (p->right != NULL) stack[++top] = p->right;
        if (p->left != NULL) stack[++top] = p->left;
    }
    free(stack);
    ret = (int *) realloc(ret, *returnSize * sizeof(int));
    return ret;
}
