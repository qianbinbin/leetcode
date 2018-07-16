#include <gtest/gtest.h>

extern "C" {
#include "construct_binary_tree_from_inorder_and_postorder_traversal.h"
}

#define ARR_SIZE(a) ((sizeof(a)/sizeof((a)[0])))

TEST(construct_binary_tree_from_inorder_and_postorder_traversal_test, buildTree_106_1) {
    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};
    struct TreeNode *root = buildTree_106_1(inorder, ARR_SIZE(inorder), postorder, ARR_SIZE(postorder));
    tree_inorder_print(root);
    tree_postorder_print(root);
    tree_free(root);
}
