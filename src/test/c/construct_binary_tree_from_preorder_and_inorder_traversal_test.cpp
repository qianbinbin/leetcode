#include <gtest/gtest.h>

extern "C" {
#include "construct_binary_tree_from_preorder_and_inorder_traversal.h"
}

#define ARR_SIZE(a) ((sizeof(a) / sizeof((a)[0])))

TEST(construct_binary_tree_from_preorder_and_inorder_traversal_test, buildTree_105_1) {
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};
    struct TreeNode *root = buildTree_105_1(preorder, ARR_SIZE(preorder), inorder, ARR_SIZE(inorder));
    tree_preorder_print(root);
    tree_inorder_print(root);
    tree_free(root);
}
