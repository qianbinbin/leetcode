#include <gtest/gtest.h>

extern "C" {
#include <recover_binary_search_tree.h>
}

TEST(leetcode_99_1, normal) {
    int nums[] = {4, 2, 6, 7, 3, 5, 1};
    struct TreeNode *tree = tree_create(nums, sizeof(nums) / sizeof(nums[0]));
    tree_inorder_print(tree);
    recoverTree_99_1(tree);
    tree_inorder_print(tree);
    tree_free(tree);
}
