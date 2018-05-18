#include <gtest/gtest.h>

extern "C" {
#include <maximum_depth_of_binary_tree.h>
}

TEST(leetcode_104, normal) {
    int nums[] = {3, 9, 20, INT_NULL_TREE_NODE, INT_NULL_TREE_NODE, 15, 7};
    struct TreeNode *tree = tree_create(nums, 7);
    EXPECT_EQ(maxDepth_104(tree), 3);
    tree_free(tree);
}
