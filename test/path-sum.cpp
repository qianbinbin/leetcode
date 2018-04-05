#include <gtest/gtest.h>

extern "C" {
#include <path-sum.h>
}

TEST(leetcode_112, normal) {
    int nums[] = {5, 4, 8, 11, INT_NULL_TREE_NODE, 13, 4, 7, 2, INT_NULL_TREE_NODE, INT_NULL_TREE_NODE,
                  INT_NULL_TREE_NODE, INT_NULL_TREE_NODE, INT_NULL_TREE_NODE, 1};
    struct TreeNode *tree = tree_create(nums, sizeof(nums) / sizeof(nums[0]));
    tree_preorder_print(tree);
    tree_inorder_print(tree);
    EXPECT_TRUE(hasPathSum_112(tree, 22));
    tree_free(tree);
}
