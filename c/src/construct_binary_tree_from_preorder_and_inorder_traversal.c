#include "construct_binary_tree_from_preorder_and_inorder_traversal.h"

#include <stdlib.h>

static struct TreeNode *build_tree(int *pre_order, int pre_offset, int *in_order, int in_offset, int len) {
    if (len == 0) return NULL;
    int root_val = pre_order[pre_offset];
    int index = in_offset;
    while (index < in_offset + len && in_order[index] != root_val) ++index;
    const int left = index - in_offset, right = len - left - 1;
    struct TreeNode *left_tree = build_tree(pre_order, pre_offset + 1, in_order, in_offset, left);
    struct TreeNode *right_tree = build_tree(pre_order, pre_offset + 1 + left, in_order, index + 1, right);
    struct TreeNode *root = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    root->val = root_val;
    root->left = left_tree;
    root->right = right_tree;
    return root;
}

struct TreeNode *buildTree_105_1(int *preorder, int preorderSize, int *inorder, int inorderSize) {
    if (preorder == NULL || preorderSize < 1 || inorder == NULL || inorderSize < 1 || preorderSize != inorderSize)
        return NULL;
    return build_tree(preorder, 0, inorder, 0, preorderSize);
}
