#include <binary_tree_preorder_traversal.h>
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

int *preorderTraversal_144_1(struct TreeNode *root, int *returnSize) {
    if (root == NULL || returnSize == NULL) return NULL;

    int left_size = 0, right_size = 0;
    int *left = preorderTraversal_144_1(root->left, &left_size);
    int *right = preorderTraversal_144_1(root->right, &right_size);

    int *ret = merge_array(&root->val, 1, left, left_size, right, right_size, returnSize);
    free(left);
    free(right);
    return ret;
}

int *preorderTraversal_144_2(struct TreeNode *root, int *returnSize) {
    if (root == NULL || returnSize == NULL) return NULL;

    int ret_capacity = 64;
    *returnSize = 0;
    int *ret = (int *) malloc(ret_capacity * sizeof(int));

    int stack_capacity = 64;
    struct TreeNode **stack = (struct TreeNode **) malloc(stack_capacity * sizeof(struct TreeNode *));
    int top = -1;
    stack[++top] = root;

    struct TreeNode *p;
    while (top != -1) {
        p = stack[top--];
        if (*returnSize == ret_capacity) {
            ret_capacity *= 2;
            ret = (int *) realloc(ret, ret_capacity * sizeof(int));
        }
        ret[(*returnSize)++] = p->val;

        if (top >= stack_capacity - 3) {
            stack_capacity *= 2;
            stack = (struct TreeNode **) realloc(stack, stack_capacity * sizeof(struct TreeNode *));
        }

        if (p->right != NULL) {
            stack[++top] = p->right;
        }
        if (p->left != NULL) {
            stack[++top] = p->left;
        }
    }
    free(stack);
    ret = (int *) realloc(ret, (*returnSize) * sizeof(int));
    return ret;
}
