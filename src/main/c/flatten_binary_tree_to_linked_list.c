#include "flatten_binary_tree_to_linked_list.h"

#include <stddef.h>

static void flatten_pre_order(struct TreeNode *root, struct TreeNode **pre) {
    if (root == NULL) return;
    if (*pre != NULL) {
        (*pre)->left = NULL;
        (*pre)->right = root;
    }
    *pre = root;
    struct TreeNode *right = root->right;
    flatten_pre_order(root->left, pre);
    flatten_pre_order(right, pre);
}

void flatten_114_1(struct TreeNode *root) {
    struct TreeNode *pre = NULL;
    flatten_pre_order(root, &pre);
}

static void flatten_reverse_pre_order(struct TreeNode *root, struct TreeNode **pre) {
    if (root == NULL) return;
    flatten_reverse_pre_order(root->right, pre);
    flatten_reverse_pre_order(root->left, pre);
    root->left = NULL;
    root->right = *pre;
    *pre = root;
}

void flatten_114_2(struct TreeNode *root) {
    struct TreeNode *pre = NULL;
    flatten_reverse_pre_order(root, &pre);
}
