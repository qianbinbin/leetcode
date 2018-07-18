#include <gtest/gtest.h>

extern "C" {
#include "flatten_binary_tree_to_linked_list.h"
}

TEST(flatten_binary_tree_to_linked_list_test, flatten_114_1) {
    int nums[] = {1, 2, 5, 3, 4, NTNODE, 6};
    struct TreeNode *root = tree_create(nums, sizeof(nums) / sizeof(nums[0]));
    flatten_114_1(root);
    tree_preorder_print(root);
    tree_inorder_print(root);
}

TEST(flatten_binary_tree_to_linked_list_test, flatten_114_2) {
    int nums[] = {1, 2, 5, 3, 4, NTNODE, 6};
    struct TreeNode *root = tree_create(nums, sizeof(nums) / sizeof(nums[0]));
    flatten_114_2(root);
    tree_preorder_print(root);
    tree_inorder_print(root);
}
