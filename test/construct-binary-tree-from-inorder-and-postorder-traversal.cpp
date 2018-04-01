#include <gtest/gtest.h>

extern "C" {
#include <construct-binary-tree-from-inorder-and-postorder-traversal.h>
}

TEST(leetcode_106, normal) {
    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};
    struct TreeNode *tree = buildTree_106(inorder, 5, postorder, 5);
    tree_inorder_print(tree);
    tree_postorder_print(tree);
    tree_free(tree);
}
