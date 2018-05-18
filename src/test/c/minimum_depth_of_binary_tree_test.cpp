#include <gtest/gtest.h>

extern "C" {
#include <minimum_depth_of_binary_tree.h>
}

TEST(leetcode_111, normal) {
    int nums[] = {1, 2, 3, 4, 5};
    struct TreeNode *tree = tree_create(nums, 5);
    EXPECT_EQ(minDepth_111(tree), 2);
    tree_free(tree);
}
