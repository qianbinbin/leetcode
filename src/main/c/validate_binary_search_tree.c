#include "validate_binary_search_tree.h"

#include <stdlib.h>

static bool is_valid_bst(struct TreeNode *root, struct TreeNode **pre) {
    if (root == NULL) return true;
    if (!is_valid_bst(root->left, pre)) return false;
    if (*pre != NULL && (*pre)->val >= root->val) return false;
    *pre = root;
    return is_valid_bst(root->right, pre);
}

bool isValidBST_98_1(struct TreeNode *root) {
    struct TreeNode *pre = NULL;
    return is_valid_bst(root, &pre);
}

bool isValidBST_98_2(struct TreeNode *root) {
    if (root == NULL) return true;
    int capacity = 16;
    struct TreeNode **stack = (struct TreeNode **) malloc(capacity * sizeof(struct TreeNode *));
    int top = -1;
    struct TreeNode *n = root, *pre = NULL;
    while (n != NULL || top != -1) {
        if (n != NULL) {
            if (top + 1 >= capacity) {
                capacity *= 2;
                stack = (struct TreeNode **) realloc(stack, capacity * sizeof(struct TreeNode *));
            }
            stack[++top] = n;
            n = n->left;
        } else {
            n = stack[top--];
            if (pre != NULL && pre->val >= n->val) {
                free(stack);
                return false;
            }
            pre = n;
            n = n->right;
        }
    }
    free(stack);
    return true;
}
