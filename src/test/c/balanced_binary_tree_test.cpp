#include <gtest/gtest.h>

extern "C" {
#include <balanced_binary_tree.h>
}

TEST(leetcode_110_1, normal) {
    int nums1[] = {3, 9, 20, NTNODE, NTNODE, 15, 7};
    struct TreeNode *tree1 = tree_create(nums1, 7);
    EXPECT_TRUE(isBalanced_110_1(tree1));
    tree_free(tree1);
    int nums2[] = {1, 2, 2, 3, 3, NTNODE, NTNODE, 4, 4};
    struct TreeNode *tree2 = tree_create(nums2, 9);
    EXPECT_FALSE(isBalanced_110_1(tree2));
    tree_free(tree2);
}

TEST(leetcode_110_2, normal) {
    int nums1[] = {3, 9, 20, NTNODE, NTNODE, 15, 7};
    struct TreeNode *tree1 = tree_create(nums1, 7);
    EXPECT_TRUE(isBalanced_110_2(tree1));
    tree_free(tree1);
    int nums2[] = {1, 2, 2, 3, 3, NTNODE, NTNODE, 4, 4};
    struct TreeNode *tree2 = tree_create(nums2, 9);
    EXPECT_FALSE(isBalanced_110_2(tree2));
    tree_free(tree2);
}
