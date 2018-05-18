#include <binary_tree_postorder_traversal.h>
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

int *postorderTraversal_145_1(struct TreeNode *root, int *returnSize) {
    if (root == NULL || returnSize == NULL) return NULL;
    int left_size = 0, right_size = 0;
    int *left = postorderTraversal_145_1(root->left, &left_size);
    int *right = postorderTraversal_145_1(root->right, &right_size);

    int *ret = merge_array(left, left_size, right, right_size, &root->val, 1, returnSize);
    free(left);
    free(right);
    return ret;
}

int *postorderTraversal_145_2(struct TreeNode *root, int *returnSize) {
    if (root == NULL || returnSize == NULL) return NULL;

    int ret_capacity = 64;
    int *ret = (int *) malloc(ret_capacity * sizeof(int));
    *returnSize = 0;

    int stack_capacity = 64;
    struct TreeNode **stack = (struct TreeNode **) malloc(stack_capacity * sizeof(struct TreeNode *));
    int top = -1;

    struct TreeNode *p = root, *top_node, *last_visited = NULL;
    while (top != -1 || p != NULL) {
        if (p != NULL) {
            if (top + 1 >= stack_capacity) {
                stack_capacity *= 2;
                stack = (struct TreeNode **) realloc(stack, stack_capacity * sizeof(struct TreeNode *));
            }
            stack[++top] = p;
            p = p->left;
        } else {
            top_node = stack[top];
            if (top_node->right != NULL && top_node->right != last_visited) {
                p = top_node->right;
            } else {
                if (*returnSize >= ret_capacity) {
                    ret_capacity *= 2;
                    ret = (int *) realloc(ret, ret_capacity * sizeof(int));
                }
                ret[(*returnSize)++] = top_node->val;
                last_visited = top_node;
                --top;
            }
        }
    }
    free(stack);
    ret = (int *) realloc(ret, (*returnSize) * sizeof(int));
    return ret;
}
