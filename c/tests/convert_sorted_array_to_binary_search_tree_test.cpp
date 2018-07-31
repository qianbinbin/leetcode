#include <gtest/gtest.h>

extern "C" {
#include "convert_sorted_array_to_binary_search_tree.h"
}

TEST(convert_sorted_array_to_binary_search_tree_test, sortedArrayToBST_108_1) {
    int nums[] = {-10, -3, 0, 5, 9};
    struct TreeNode *root = sortedArrayToBST_108_1(nums, 5);
    tree_preorder_print(root);
    tree_inorder_print(root);
    tree_free(root);
}
