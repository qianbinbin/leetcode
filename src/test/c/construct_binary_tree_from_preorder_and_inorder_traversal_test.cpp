#include <gtest/gtest.h>

extern "C" {
#include <construct_binary_tree_from_preorder_and_inorder_traversal.h>
}

TEST(leetcode_105, normal) {
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};
    struct TreeNode *tree = buildTree_105(preorder, 5, inorder, 5);
    tree_preorder_print(tree);
    tree_inorder_print(tree);
    tree_free(tree);
}
