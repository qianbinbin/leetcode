#include <gtest/gtest.h>

extern "C" {
#include "path_sum.h"
}

TEST(path_sum_test, hasPathSum_112_1) {
    int nums1[] = {5, 4, 8, 11, NTNODE, 13, 4, 7, 2, NTNODE, NTNODE, NTNODE,
                   NTNODE, NTNODE, 1};
    struct TreeNode *root1 = tree_create(nums1,
                                         sizeof(nums1) / sizeof(nums1[0]));
    int const targetSum1 = 22;
    EXPECT_TRUE(hasPathSum_112_1(root1, targetSum1));
    tree_free(root1);

    int nums2[] = {1, 2, 3};
    struct TreeNode *root2 = tree_create(nums2,
                                         sizeof(nums2) / sizeof(nums2[0]));
    int const targetSum2 = 5;
    EXPECT_FALSE(hasPathSum_112_1(root2, targetSum2));
    tree_free(root2);

    struct TreeNode *root3 = NULL;
    int const targetSum3 = 0;
    EXPECT_FALSE(hasPathSum_112_1(root3, targetSum3));
    tree_free(root3);
}
