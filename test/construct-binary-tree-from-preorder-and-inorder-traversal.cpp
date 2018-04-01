#include <gtest/gtest.h>

extern "C" {
#include <construct-binary-tree-from-preorder-and-inorder-traversal.h>
}

TEST(leetcode_105, normal) {
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};
    struct TreeNode *tree = buildTree_105(preorder, 5, inorder, 5);
    tree_preorder_print(tree);
    tree_inorder_print(tree);
    tree_free(tree);
}
