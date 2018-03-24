#include <binary-tree-inorder-traversal.h>
#include <stdlib.h>

int *merge_array(int *a, int size_a, int *b, int size_b, int *c, int size_c, int *size) {
    int *ret = (int *) malloc((size_a + size_b + size_c) * sizeof(int));
    *size = 0;
    if (a != NULL) {
        for (int i = 0; i < size_a; ++i) {
            ret[(*size)++] = a[i];
        }
    }
    if (b != NULL) {
        for (int i = 0; i < size_b; ++i) {
            ret[(*size)++] = b[i];
        }
    }
    if (c != NULL) {
        for (int i = 0; i < size_c; ++i) {
            ret[(*size)++] = c[i];
        }
    }
    return ret;
}

int *inorderTraversal_94_1(struct TreeNode *root, int *returnSize) {
    if (root == NULL || returnSize == NULL) return NULL;

    int left_size = 0, right_size = 0;
    int *left = inorderTraversal_94_1(root->left, &left_size);
    int *right = inorderTraversal_94_1(root->right, &right_size);

    int *ret = merge_array(left, left_size, &root->val, 1, right, right_size, returnSize);
    free(left);
    free(right);
    return ret;
}

int *inorderTraversal_94_2(struct TreeNode *root, int *returnSize) {
    if (root == NULL || returnSize == NULL) return NULL;

    int ret_capacity = 64;
    int *ret = (int *) malloc(ret_capacity * sizeof(int));
    *returnSize = 0;

    int stack_capicity = 64;
    struct TreeNode **stack = (struct TreeNode **) malloc(stack_capicity * sizeof(struct TreeNode *));
    int top = -1;

    struct TreeNode *p = root;
    while (top != -1 || p != NULL) {
        if (p != NULL) {
            if (top + 1 >= stack_capicity) {
                stack_capicity *= 2;
                stack = (struct TreeNode **) realloc(stack, stack_capicity * sizeof(struct TreeNode *));
            }
            stack[++top] = p;
            p = p->left;
        } else {
            p = stack[top--];
            if (*returnSize >= ret_capacity) {
                ret_capacity *= 2;
                ret = (int *) realloc(ret, ret_capacity * sizeof(int));
            }
            ret[(*returnSize)++] = p->val;
            p = p->right;
        }
    }
    free(stack);
    ret = (int *) realloc(ret, (*returnSize) * sizeof(int));
    return ret;
}
