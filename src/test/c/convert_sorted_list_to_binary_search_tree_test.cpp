#include <gtest/gtest.h>

extern "C" {
#include "convert_sorted_list_to_binary_search_tree.h"
}

TEST(convert_sorted_list_to_binary_search_tree_test, sortedListToBST_109_1) {
    int nums[] = {-10, -3, 0, 5, 9};
    struct ListNode *head = list_create(nums, 5);
    struct TreeNode *root = sortedListToBST_109_1(head);
    tree_preorder_print(root);
    tree_inorder_print(root);
    tree_free(root);
    list_free(head);
}
