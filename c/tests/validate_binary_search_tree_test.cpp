#include <gtest/gtest.h>

extern "C" {
#include "validate_binary_search_tree.h"
}

TEST(validate_binary_search_tree_test, isValidBST_98_1) {
    int nums1[] = {2, 1, 3};
    struct TreeNode *root1 = tree_create(nums1,
                                         sizeof(nums1) / sizeof(nums1[0]));
    EXPECT_TRUE(isValidBST_98_1(root1));
    tree_free(root1);
    int nums2[] = {5, 1, 4, NTNODE, NTNODE, 3, 6};
    struct TreeNode *root2 = tree_create(nums2,
                                         sizeof(nums2) / sizeof(nums2[0]));
    EXPECT_FALSE(isValidBST_98_1(root2));
    tree_free(root2);
}

TEST(validate_binary_search_tree_test, isValidBST_98_2) {
    int nums1[] = {2, 1, 3};
    struct TreeNode *root1 = tree_create(nums1,
                                         sizeof(nums1) / sizeof(nums1[0]));
    EXPECT_TRUE(isValidBST_98_2(root1));
    tree_free(root1);
    int nums2[] = {5, 1, 4, NTNODE, NTNODE, 3, 6};
    struct TreeNode *root2 = tree_create(nums2,
                                         sizeof(nums2) / sizeof(nums2[0]));
    EXPECT_FALSE(isValidBST_98_2(root2));
    tree_free(root2);
}

TEST(validate_binary_search_tree_test, isValidBST_98_3) {
    int nums1[] = {2, 1, 3};
    struct TreeNode *root1 = tree_create(nums1,
                                         sizeof(nums1) / sizeof(nums1[0]));
    EXPECT_TRUE(isValidBST_98_3(root1));
    tree_free(root1);
    int nums2[] = {5, 1, 4, NTNODE, NTNODE, 3, 6};
    struct TreeNode *root2 = tree_create(nums2,
                                         sizeof(nums2) / sizeof(nums2[0]));
    EXPECT_FALSE(isValidBST_98_3(root2));
    tree_free(root2);
}
