#include <gtest/gtest.h>

extern "C" {
#include "symmetric_tree.h"
}

TEST(symmetric_tree_test, isSymmetric_101_1) {
    int nums1[] = {1, 2, 2, 3, 4, 4, 3};
    struct TreeNode *root1 = tree_create(nums1,
                                         sizeof(nums1) / sizeof(nums1[0]));
    EXPECT_TRUE(isSymmetric_101_1(root1));
    tree_free(root1);

    int nums2[] = {1, 2, 2, NTNODE, 3, NTNODE, 3};
    struct TreeNode *root2 = tree_create(nums2,
                                         sizeof(nums2) / sizeof(nums2[0]));
    EXPECT_FALSE(isSymmetric_101_1(root2));
    tree_free(root2);
}

TEST(symmetric_tree_test, isSymmetric_101_2) {
    int nums1[] = {1, 2, 2, 3, 4, 4, 3};
    struct TreeNode *root1 = tree_create(nums1,
                                         sizeof(nums1) / sizeof(nums1[0]));
    EXPECT_TRUE(isSymmetric_101_2(root1));
    tree_free(root1);

    int nums2[] = {1, 2, 2, NTNODE, 3, NTNODE, 3};
    struct TreeNode *root2 = tree_create(nums2,
                                         sizeof(nums2) / sizeof(nums2[0]));
    EXPECT_FALSE(isSymmetric_101_2(root2));
    tree_free(root2);
}
