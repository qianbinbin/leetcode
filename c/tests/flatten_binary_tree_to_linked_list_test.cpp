#include <gtest/gtest.h>

extern "C" {
#include "flatten_binary_tree_to_linked_list.h"
}

TEST(flatten_binary_tree_to_linked_list_test, flatten_114_1) {
    int nums1[] = {1, 2, 5, 3, 4, NTNODE, 6};
    struct TreeNode *root1 = tree_create(nums1,
                                         sizeof(nums1) / sizeof(nums1[0]));
    flatten_114_1(root1);
    tree_preorder_print(root1);
    tree_inorder_print(root1);

    struct TreeNode *root2 = NULL;
    flatten_114_1(root2);
    tree_preorder_print(root2);
    tree_inorder_print(root2);

    int nums3[] = {0};
    struct TreeNode *root3 = tree_create(nums3,
                                         sizeof(nums3) / sizeof(nums3[0]));
    flatten_114_1(root3);
    tree_preorder_print(root3);
    tree_inorder_print(root3);
}

TEST(flatten_binary_tree_to_linked_list_test, flatten_114_2) {
    int nums1[] = {1, 2, 5, 3, 4, NTNODE, 6};
    struct TreeNode *root1 = tree_create(nums1,
                                         sizeof(nums1) / sizeof(nums1[0]));
    flatten_114_2(root1);
    tree_preorder_print(root1);
    tree_inorder_print(root1);

    struct TreeNode *root2 = NULL;
    flatten_114_2(root2);
    tree_preorder_print(root2);
    tree_inorder_print(root2);

    int nums3[] = {0};
    struct TreeNode *root3 = tree_create(nums3,
                                         sizeof(nums3) / sizeof(nums3[0]));
    flatten_114_2(root3);
    tree_preorder_print(root3);
    tree_inorder_print(root3);
}
