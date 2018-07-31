#include <gtest/gtest.h>

extern "C" {
#include "recover_binary_search_tree.h"
}

TEST(recover_binary_search_tree_test, recoverTree_99_1) {
    int nums1[] = {1, 3, NTNODE, NTNODE, 2};
    struct TreeNode *tree1 = tree_create(nums1, sizeof(nums1) / sizeof(nums1[0]));
    tree_inorder_print(tree1);
    recoverTree_99_1(tree1);
    tree_inorder_print(tree1);
    tree_free(tree1);

    int nums2[] = {3, 1, 4, NTNODE, NTNODE, 2};
    struct TreeNode *tree2 = tree_create(nums2, sizeof(nums2) / sizeof(nums2[0]));
    tree_inorder_print(tree2);
    recoverTree_99_1(tree2);
    tree_inorder_print(tree2);
    tree_free(tree2);
}

TEST(recover_binary_search_tree_test, recoverTree_99_2) {
    int nums1[] = {1, 3, NTNODE, NTNODE, 2};
    struct TreeNode *tree1 = tree_create(nums1, sizeof(nums1) / sizeof(nums1[0]));
    tree_inorder_print(tree1);
    recoverTree_99_2(tree1);
    tree_inorder_print(tree1);
    tree_free(tree1);

    int nums2[] = {3, 1, 4, NTNODE, NTNODE, 2};
    struct TreeNode *tree2 = tree_create(nums2, sizeof(nums2) / sizeof(nums2[0]));
    tree_inorder_print(tree2);
    recoverTree_99_2(tree2);
    tree_inorder_print(tree2);
    tree_free(tree2);
}
