#include "construct_binary_tree_from_preorder_and_inorder_traversal.h"

#include <stdlib.h>

static struct TreeNode *
build_tree(int *pre_order, int pre_pos, int *in_order, int in_pos,
           int len) {
    if (len == 0)
        return NULL;
    int root_val = pre_order[pre_pos];
    int pos = in_pos;
    for (int e = in_pos + len;
         pos < e && in_order[pos] != root_val; ++pos);
    const int left = pos - in_pos, right = len - left - 1;
    struct TreeNode *left_tree = build_tree(pre_order, pre_pos + 1, in_order,
                                            in_pos, left);
    struct TreeNode *right_tree = build_tree(pre_order, pre_pos + 1 + left,
                                             in_order, pos + 1, right);
    struct TreeNode *root = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    root->val = root_val;
    root->left = left_tree;
    root->right = right_tree;
    return root;
}

struct TreeNode *buildTree_105_1(int *preorder, int preorderSize, int *inorder,
                                 int inorderSize) {
    return build_tree(preorder, 0, inorder, 0, preorderSize);
}
