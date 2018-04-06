#include <gtest/gtest.h>

extern "C" {
#include <sum-root-to-leaf-numbers.h>
}

TEST(leetcode_129, normal) {
    int nums[] = {1, 2, 3};
    struct TreeNode *tree = tree_create(nums, 3);
    tree_preorder_print(tree);
    EXPECT_EQ(sumNumbers_129(tree), 25);
    tree_free(tree);
}
