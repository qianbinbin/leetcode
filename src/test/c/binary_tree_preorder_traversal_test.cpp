#include <gtest/gtest.h>

extern "C" {
#include <binary_tree_preorder_traversal.h>
}

TEST(leetcode_144_1, normal) {
    int nums[] = {1, NTNODE, 2, NTNODE, NTNODE, 3, NTNODE};
    struct TreeNode *tree = tree_create(nums, 7);
    int size = 0;
    int *ret = preorderTraversal_144_1(tree, &size);
    array_print(ret, size);
    free(ret);
    tree_free(tree);
}

TEST(leetcode_144_2, normal) {
    int nums[] = {1, NTNODE, 2, NTNODE, NTNODE, 3, NTNODE};
    struct TreeNode *tree = tree_create(nums, 7);
    int size = 0;
    int *ret = preorderTraversal_144_2(tree, &size);
    array_print(ret, size);
    free(ret);
    tree_free(tree);
}
