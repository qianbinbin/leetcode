#include <gtest/gtest.h>

extern "C" {
#include "minimum_depth_of_binary_tree.h"
}

TEST(minimum_depth_of_binary_tree_test, minDepth_111_1) {
    int nums1[] = {3, 9, 20, NTNODE, NTNODE, 15, 7};
    struct TreeNode *root1 = tree_create(nums1,
                                         sizeof(nums1) / sizeof(nums1[0]));
    int const expected1 = 2;
    EXPECT_EQ(expected1, minDepth_111_1(root1));
    tree_free(root1);

    int nums2[] = {2, NTNODE, 3, NTNODE, NTNODE, NTNODE, 4, NTNODE, NTNODE,
                   NTNODE, NTNODE, NTNODE, NTNODE, NTNODE, 5, NTNODE, NTNODE,
                   NTNODE, NTNODE, NTNODE, NTNODE, NTNODE, NTNODE, NTNODE,
                   NTNODE, NTNODE, NTNODE, NTNODE, NTNODE, NTNODE, 6};
    struct TreeNode *root2 = tree_create(nums2,
                                         sizeof(nums2) / sizeof(nums2[0]));
    int const expected2 = 5;
    EXPECT_EQ(expected2, minDepth_111_1(root2));
    tree_free(root2);
}
