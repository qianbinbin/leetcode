#include <binary-tree-postorder-traversal.h>
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
