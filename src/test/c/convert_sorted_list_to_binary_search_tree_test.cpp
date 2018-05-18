#include <gtest/gtest.h>

extern "C" {
#include <convert_sorted_list_to_binary_search_tree.h>
}

TEST(leetcode_109, normal) {
    int nums[] = {-10, -3, 0, 5, 9};
    struct ListNode *head = list_from_array(nums, 5);
    list_print(head);
    struct TreeNode *tree = sortedListToBST_109(head);
    tree_preorder_print(tree);
    tree_inorder_print(tree);
    tree_free(tree);
    list_free(head);
}
