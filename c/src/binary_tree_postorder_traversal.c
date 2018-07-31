#include "binary_tree_postorder_traversal.h"

#include <stdlib.h>

static void post_order_traversal(struct TreeNode *root, int **result, int *size, int *capacity) {
    if (root == NULL) return;
    post_order_traversal(root->left, result, size, capacity);
    post_order_traversal(root->right, result, size, capacity);
    if (*size >= *capacity) {
        *capacity *= 2;
        *result = (int *) realloc(*result, *capacity * sizeof(int));
    }
    (*result)[(*size)++] = root->val;
}

int *postorderTraversal_145_1(struct TreeNode *root, int *returnSize) {
    if (root == NULL || returnSize == NULL) return NULL;

    int capacity = 16;
    int *ret = (int *) malloc(capacity * sizeof(int));
    *returnSize = 0;
    post_order_traversal(root, &ret, returnSize, &capacity);
    ret = (int *) realloc(ret, *returnSize * sizeof(int));
    return ret;
}

int *postorderTraversal_145_2(struct TreeNode *root, int *returnSize) {
    if (root == NULL || returnSize == NULL) return NULL;

    int capacity = 16;
    int *ret = (int *) malloc(capacity * sizeof(int));
    *returnSize = 0;

    int stack_capacity = 16;
    struct TreeNode **stack = (struct TreeNode **) malloc(stack_capacity * sizeof(struct TreeNode *));
    int top = -1;

    struct TreeNode *p = root, *parent, *pre = NULL;
    while (top != -1 || p != NULL) {
        if (p != NULL) {
            if (top + 1 >= stack_capacity) {
                stack_capacity *= 2;
                stack = (struct TreeNode **) realloc(stack, stack_capacity * sizeof(struct TreeNode *));
            }
            stack[++top] = p;
            p = p->left;
        } else {
            parent = stack[top];
            if (parent->right != NULL && parent->right != pre) {
                p = parent->right;
            } else {
                if (*returnSize >= capacity) {
                    capacity *= 2;
                    ret = (int *) realloc(ret, capacity * sizeof(int));
                }
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
    if (root == NULL || returnSize == NULL) return NULL;

    int stack_capacity = 16;
    void **stack = (void **) malloc(stack_capacity * sizeof(void *));
    int top = -1;
    stack[++top] = root;

    int capacity = 16;
    int *ret = (int *) malloc(capacity * sizeof(int));
    *returnSize = 0;

    struct TreeNode *node;
    while (top != -1) {
        node = stack[top--];
        if (top + 1 + 2 >= stack_capacity) {
            stack_capacity *= 2;
            stack = (void **) realloc(stack, stack_capacity * sizeof(void *));
        }
        if (node->left != NULL) stack[++top] = node->left;
        if (node->right != NULL) stack[++top] = node->right;

        if (*returnSize >= capacity) {
            capacity *= 2;
            ret = (int *) realloc(ret, capacity * sizeof(int));
        }
        ret[(*returnSize)++] = node->val;
    }
    free(stack);
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
