#include <gtest/gtest.h>

extern "C" {
#include <symmetric_tree.h>
}

TEST(leetcode_101_1, normal) {
    int nums1[] = {1, 2, 2, 3, 4, 4, 3};
    struct TreeNode *tree1 = tree_create(nums1, 7);
    EXPECT_TRUE(isSymmetric_101_1(tree1));
    tree_free(tree1);
    int nums2[] = {1, 2, 2, INT_NULL_TREE_NODE, 3, INT_NULL_TREE_NODE, 3};
    struct TreeNode *tree2 = tree_create(nums2, 7);
    EXPECT_FALSE(isSymmetric_101_1(tree2));
    tree_free(tree2);
}

TEST(leetcode_101_2, normal) {
    int nums1[] = {1, 2, 2, 3, 4, 4, 3};
    struct TreeNode *tree1 = tree_create(nums1, 7);
    EXPECT_TRUE(isSymmetric_101_2(tree1));
    tree_free(tree1);
    int nums2[] = {1, 2, 2, INT_NULL_TREE_NODE, 3, INT_NULL_TREE_NODE, 3};
    struct TreeNode *tree2 = tree_create(nums2, 7);
    EXPECT_FALSE(isSymmetric_101_2(tree2));
    tree_free(tree2);
}
