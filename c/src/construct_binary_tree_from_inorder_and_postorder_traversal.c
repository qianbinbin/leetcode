#include "construct_binary_tree_from_inorder_and_postorder_traversal.h"

#include <stdlib.h>

static struct TreeNode *
build_tree(int *in_order, int in_pos, int *post_order, int post_pos, int len) {
    if (len == 0)
        return NULL;

    const int root_val = post_order[post_pos + len - 1];
    int pos = in_pos;
    for (int e = in_pos + len; pos < e && in_order[pos] != root_val; ++pos);
    const int left = pos - in_pos, right = len - left - 1;
    struct TreeNode *left_tree = build_tree(in_order, in_pos, post_order,
                                            post_pos, left);
    struct TreeNode *right_tree = build_tree(in_order, in_pos + 1 + left,
                                             post_order, post_pos + left,
                                             right);
    struct TreeNode *root = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    root->val = root_val;
    root->left = left_tree;
    root->right = right_tree;
    return root;
}

struct TreeNode *buildTree_106_1(int *inorder, int inorderSize, int *postorder,
                                 int postorderSize) {
    return build_tree(inorder, 0, postorder, 0, inorderSize);
}
