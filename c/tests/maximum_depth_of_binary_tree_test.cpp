#include <gtest/gtest.h>

extern "C" {
#include "maximum_depth_of_binary_tree.h"
}

TEST(maximum_depth_of_binary_tree_test, maxDepth_104_1) {
    int nums1[] = {3, 9, 20, NTNODE, NTNODE, 15, 7};
    int const expected1 = 3;
    struct TreeNode *root1 = tree_create(nums1,
                                         sizeof(nums1) / sizeof(nums1[0]));
    EXPECT_EQ(expected1, maxDepth_104_1(root1));
    tree_free(root1);

    int nums2[] = {1, NTNODE, 2};
    int const expected2 = 2;
    struct TreeNode *root2 = tree_create(nums2,
                                         sizeof(nums2) / sizeof(nums2[0]));
    EXPECT_EQ(expected2, maxDepth_104_1(root2));
    tree_free(root2);
}
