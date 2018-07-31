#include <gtest/gtest.h>

extern "C" {
#include "path_sum.h"
}

TEST(path_sum_test, hasPathSum_112_1) {
    int nums[] = {5, 4, 8, 11, NTNODE, 13, 4, 7, 2, NTNODE, NTNODE, NTNODE, NTNODE, NTNODE, 1};
    struct TreeNode *root = tree_create(nums, sizeof(nums) / sizeof(nums[0]));
    EXPECT_TRUE(hasPathSum_112_1(root, 22));
    tree_free(root);
}
