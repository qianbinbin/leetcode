#include <gtest/gtest.h>

extern "C" {
#include "recover_binary_search_tree.h"
}

TEST(recover_binary_search_tree_test, recoverTree_99_1) {
    int nums1[] = {1, 3, NTNODE, NTNODE, 2};
    struct TreeNode *root1 = tree_create(nums1,
                                         sizeof(nums1) / sizeof(nums1[0]));
    tree_inorder_print(root1);
    recoverTree_99_1(root1);
    tree_inorder_print(root1);
    tree_free(root1);

    int nums2[] = {3, 1, 4, NTNODE, NTNODE, 2};
    struct TreeNode *root2 = tree_create(nums2,
                                         sizeof(nums2) / sizeof(nums2[0]));
    tree_inorder_print(root2);
    recoverTree_99_1(root2);
    tree_inorder_print(root2);
    tree_free(root2);
}

TEST(recover_binary_search_tree_test, recoverTree_99_2) {
    int nums1[] = {1, 3, NTNODE, NTNODE, 2};
    struct TreeNode *root1 = tree_create(nums1,
                                         sizeof(nums1) / sizeof(nums1[0]));
    tree_inorder_print(root1);
    recoverTree_99_2(root1);
    tree_inorder_print(root1);
    tree_free(root1);

    int nums2[] = {3, 1, 4, NTNODE, NTNODE, 2};
    struct TreeNode *root2 = tree_create(nums2,
                                         sizeof(nums2) / sizeof(nums2[0]));
    tree_inorder_print(root2);
    recoverTree_99_2(root2);
    tree_inorder_print(root2);
    tree_free(root2);
}
