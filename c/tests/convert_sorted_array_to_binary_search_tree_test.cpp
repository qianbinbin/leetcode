#include <gtest/gtest.h>

extern "C" {
#include "convert_sorted_array_to_binary_search_tree.h"
}

TEST(convert_sorted_array_to_binary_search_tree_test, sortedArrayToBST_108_1) {
    int nums1[] = {-10, -3, 0, 5, 9};
    struct TreeNode *actual1 = sortedArrayToBST_108_1(nums1, sizeof(nums1) /
                                                             sizeof(nums1[0]));
    tree_preorder_print(actual1);
    tree_inorder_print(actual1);
    tree_free(actual1);

    int nums2[] = {1, 3};
    struct TreeNode *actual2 = sortedArrayToBST_108_1(nums2, sizeof(nums2) /
                                                             sizeof(nums2[0]));
    tree_preorder_print(actual2);
    tree_inorder_print(actual2);
    tree_free(actual2);
}
