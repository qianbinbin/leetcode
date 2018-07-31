#include <gtest/gtest.h>

extern "C" {
#include "binary_tree_inorder_traversal.h"
}

TEST(binary_tree_inorder_traversal_test, inorderTraversal_94_1) {
    int nums[] = {1, NTNODE, 2, NTNODE, NTNODE, 3};
    struct TreeNode *tree = tree_create(nums, sizeof(nums) / sizeof(nums[0]));
    int size = 0;
    int *ret = inorderTraversal_94_1(tree, &size);
    array_print(ret, size);
    free(ret);
    tree_free(tree);
}

TEST(binary_tree_inorder_traversal_test, inorderTraversal_94_2) {
    int nums[] = {1, NTNODE, 2, NTNODE, NTNODE, 3};
    struct TreeNode *tree = tree_create(nums, sizeof(nums) / sizeof(nums[0]));
    int size = 0;
    int *ret = inorderTraversal_94_2(tree, &size);
    array_print(ret, size);
    free(ret);
    tree_free(tree);
}
