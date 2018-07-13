#include <gtest/gtest.h>

extern "C" {
#include "validate_binary_search_tree.h"
}

TEST(validate_binary_search_tree_test, isValidBST_98_1) {
    int nums1[] = {2, 1, 3};
    struct TreeNode *tree1 = tree_create(nums1, sizeof(nums1) / sizeof(nums1[0]));
    EXPECT_TRUE(isValidBST_98_1(tree1));
    tree_free(tree1);
    int nums2[] = {5, 1, 4, NTNODE, NTNODE, 3, 6};
    struct TreeNode *tree2 = tree_create(nums2, sizeof(nums2) / sizeof(nums2[0]));
    EXPECT_FALSE(isValidBST_98_1(tree2));
    tree_free(tree2);
}

TEST(validate_binary_search_tree_test, isValidBST_98_2) {
    int nums1[] = {2, 1, 3};
    struct TreeNode *tree1 = tree_create(nums1, sizeof(nums1) / sizeof(nums1[0]));
    EXPECT_TRUE(isValidBST_98_2(tree1));
    tree_free(tree1);
    int nums2[] = {5, 1, 4, NTNODE, NTNODE, 3, 6};
    struct TreeNode *tree2 = tree_create(nums2, sizeof(nums2) / sizeof(nums2[0]));
    EXPECT_FALSE(isValidBST_98_2(tree2));
    tree_free(tree2);
}
