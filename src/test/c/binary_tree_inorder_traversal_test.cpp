#include <gtest/gtest.h>

extern "C" {
#include <binary_tree_inorder_traversal.h>
}

TEST(leetcode_94_1, normal) {
    int nums[] = {1, INT_NULL_TREE_NODE, 2, INT_NULL_TREE_NODE, INT_NULL_TREE_NODE, 3, INT_NULL_TREE_NODE};
    struct TreeNode *tree = tree_create(nums, 7);
    int size = 0;
    int *ret = inorderTraversal_94_1(tree, &size);
    array_print(ret, size);
    free(ret);
    tree_free(tree);
}

TEST(leetcode_94_2, normal) {
    int nums[] = {1, INT_NULL_TREE_NODE, 2, INT_NULL_TREE_NODE, INT_NULL_TREE_NODE, 3, INT_NULL_TREE_NODE};
    struct TreeNode *tree = tree_create(nums, 7);
    int size = 0;
    int *ret = inorderTraversal_94_2(tree, &size);
    array_print(ret, size);
    free(ret);
    tree_free(tree);
}
