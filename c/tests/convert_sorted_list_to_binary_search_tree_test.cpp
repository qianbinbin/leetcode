#include <gtest/gtest.h>

extern "C" {
#include "convert_sorted_list_to_binary_search_tree.h"
}

TEST(convert_sorted_list_to_binary_search_tree_test, sortedListToBST_109_1) {
    int nums1[] = {-10, -3, 0, 5, 9};
    struct ListNode *head1 = list_create(nums1,
                                         sizeof(nums1) / sizeof(nums1[0]));
    struct TreeNode *actual1 = sortedListToBST_109_1(head1);
    tree_preorder_print(actual1);
    tree_inorder_print(actual1);
    tree_free(actual1);
    list_free(head1);

    int nums2[] = {};
    struct ListNode *head2 = list_create(nums2,
                                         sizeof(nums2) / sizeof(nums2[0]));
    struct TreeNode *actual2 = sortedListToBST_109_1(head2);
    tree_preorder_print(actual2);
    tree_inorder_print(actual2);
    tree_free(actual2);
    list_free(head2);
}
