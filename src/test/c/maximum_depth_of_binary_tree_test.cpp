#include <gtest/gtest.h>

extern "C" {
#include "maximum_depth_of_binary_tree.h"
}

TEST(maximum_depth_of_binary_tree_test, maxDepth_104_1) {
    int nums[] = {3, 9, 20, NTNODE, NTNODE, 15, 7};
    struct TreeNode *tree = tree_create(nums, sizeof(nums) / sizeof(nums[0]));
    EXPECT_EQ(maxDepth_104_1(tree), 3);
    tree_free(tree);
}
