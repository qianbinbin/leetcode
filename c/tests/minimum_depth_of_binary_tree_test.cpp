#include <gtest/gtest.h>

extern "C" {
#include "minimum_depth_of_binary_tree.h"
}

TEST(minimum_depth_of_binary_tree_test, minDepth_111_1) {
    int nums[] = {3, 9, 20, NTNODE, NTNODE, 15, 7};
    struct TreeNode *root = tree_create(nums, sizeof(nums) / sizeof(nums[0]));
    EXPECT_EQ(minDepth_111_1(root), 2);
    tree_free(root);
}
