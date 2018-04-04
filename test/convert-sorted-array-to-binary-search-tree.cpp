#include <gtest/gtest.h>

extern "C" {
#include <convert-sorted-array-to-binary-search-tree.h>
}

TEST(leetcode_108, normal) {
    int nums[] = {-10, -3, 0, 5, 9};
    struct TreeNode *tree = sortedArrayToBST_108(nums, 5);
    tree_preorder_print(tree);
    tree_inorder_print(tree);
    tree_free(tree);
}
