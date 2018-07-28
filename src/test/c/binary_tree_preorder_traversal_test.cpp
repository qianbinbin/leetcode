#include <gtest/gtest.h>

extern "C" {
#include "binary_tree_preorder_traversal.h"
}

#define ARR_SIZE(a) (sizeof(a) / sizeof((a)[0]))

TEST(binary_tree_preorder_traversal_test, preorderTraversal_144_1) {
    int nums[] = {1, NTNODE, 2, NTNODE, NTNODE, 3};
    struct TreeNode *root = tree_create(nums, ARR_SIZE(nums));
    int size = 0;
    int *ret = preorderTraversal_144_1(root, &size);
    array_print(ret, size);
    free(ret);
    tree_free(root);
}

TEST(binary_tree_preorder_traversal_test, preorderTraversal_144_2) {
    int nums[] = {1, NTNODE, 2, NTNODE, NTNODE, 3};
    struct TreeNode *root = tree_create(nums, ARR_SIZE(nums));
    int size = 0;
    int *ret = preorderTraversal_144_2(root, &size);
    array_print(ret, size);
    free(ret);
    tree_free(root);
}
