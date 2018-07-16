#include "construct_binary_tree_from_inorder_and_postorder_traversal.h"

#include <stdlib.h>

static struct TreeNode *build_tree(int *in_order, int in_offset, int *post_order, int post_offset, int len) {
    if (len == 0) return NULL;

    const int root_val = post_order[post_offset + len - 1];
    int index = in_offset;
    while (index < in_offset + len && in_order[index] != root_val) ++index;
    const int left = index - in_offset, right = len - left - 1;
    struct TreeNode *left_tree = build_tree(in_order, in_offset, post_order, post_offset, left);
    struct TreeNode *right_tree = build_tree(in_order, in_offset + 1 + left, post_order, post_offset + left, right);
    struct TreeNode *root = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    root->val = root_val;
    root->left = left_tree;
    root->right = right_tree;
    return root;
}

struct TreeNode *buildTree_106_1(int *inorder, int inorderSize, int *postorder, int postorderSize) {
    if (inorder == NULL || inorderSize < 1 || postorder == NULL || postorderSize < 1 || inorderSize != postorderSize)
        return NULL;
    return build_tree(inorder, 0, postorder, 0, inorderSize);
}
