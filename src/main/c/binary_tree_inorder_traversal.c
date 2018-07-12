#include "binary_tree_inorder_traversal.h"

#include <stdlib.h>

static void in_order(struct TreeNode *root, int **ret, int *capacity, int *size) {
    if (root == NULL) return;
    in_order(root->left, ret, capacity, size);
    if (*size >= *capacity) {
        *capacity *= 2;
        *ret = (int *) realloc(*ret, *capacity * sizeof(int));
    }
    (*ret)[(*size)++] = root->val;
    in_order(root->right, ret, capacity, size);
}

int *inorderTraversal_94_1(struct TreeNode *root, int *returnSize) {
    if (root == NULL || returnSize == NULL) return NULL;

    int capacity = 16;
    int *ret = (int *) malloc(capacity * sizeof(int));
    *returnSize = 0;
    in_order(root, &ret, &capacity, returnSize);
    ret = (int *) realloc(ret, *returnSize * sizeof(int));
    return ret;
}

int *inorderTraversal_94_2(struct TreeNode *root, int *returnSize) {
    if (root == NULL || returnSize == NULL) return NULL;

    int capacity = 16;
    int *ret = (int *) malloc(capacity * sizeof(int));
    *returnSize = 0;

    int stack_capacity = 16;
    struct TreeNode **stack = (struct TreeNode **) malloc(stack_capacity * sizeof(struct TreeNode *));
    int top = -1;

    struct TreeNode *p = root;
    while (top != -1 || p != NULL) {
        if (p != NULL) {
            if (top + 1 >= stack_capacity) {
                stack_capacity *= 2;
                stack = (struct TreeNode **) realloc(stack, stack_capacity * sizeof(struct TreeNode *));
            }
            stack[++top] = p;
            p = p->left;
        } else {
            p = stack[top--];
            if (*returnSize >= capacity) {
                capacity *= 2;
                ret = (int *) realloc(ret, capacity * sizeof(int));
            }
            ret[(*returnSize)++] = p->val;
            p = p->right;
        }
    }
    free(stack);
    ret = (int *) realloc(ret, *returnSize * sizeof(int));
    return ret;
}
