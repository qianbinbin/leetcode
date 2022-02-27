#include <gtest/gtest.h>

extern "C" {
#include "binary_tree_maximum_path_sum.h"
}

#define ARR_SIZE(a) (sizeof(a) / sizeof((a)[0]))

TEST(binary_tree_maximum_path_sum_test, maxPathSum_124_1) {
    int nums1[] = {1, 2, 3};
    struct TreeNode *root1 = tree_create(nums1, ARR_SIZE(nums1));
    int const expected1 = 6;
    EXPECT_EQ(expected1, maxPathSum_124_1(root1));
    tree_free(root1);

    int nums2[] = {-10, 9, 20, NTNODE, NTNODE, 15, 7};
    struct TreeNode *root2 = tree_create(nums2, ARR_SIZE(nums2));
    int const expected2 = 42;
    EXPECT_EQ(expected2, maxPathSum_124_1(root2));
    tree_free(root2);
}
