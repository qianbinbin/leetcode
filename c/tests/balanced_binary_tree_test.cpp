#include <gtest/gtest.h>

extern "C" {
#include "balanced_binary_tree.h"
}

TEST(balanced_binary_tree_test, isBalanced_110_1) {
    int nums1[] = {3, 9, 20, NTNODE, NTNODE, 15, 7};
    struct TreeNode *root1 = tree_create(nums1, 7);
    EXPECT_TRUE(isBalanced_110_1(root1));
    tree_free(root1);
    int nums2[] = {1, 2, 2, 3, 3, NTNODE, NTNODE, 4, 4};
    struct TreeNode *root2 = tree_create(nums2, 9);
    EXPECT_FALSE(isBalanced_110_1(root2));
    tree_free(root2);
}
