#include <gtest/gtest.h>

extern "C" {
#include <binary_tree_zigzag_level_order_traversal.h>
}

TEST(leetcode_103, normal) {
    int nums[] = {3, 9, 20, INT_NULL_TREE_NODE, INT_NULL_TREE_NODE, 15, 7};
    struct TreeNode *tree = tree_create(nums, 7);
    int size = 0;
    int *columnSizes = (int *) malloc(sizeof(int));
    int **ret = zigzagLevelOrder_103(tree, &columnSizes, &size);
    for (int i = 0; i < size; ++i) {
        array_print(ret[i], columnSizes[i]);
        free(ret[i]);
    }
    free(ret);
    free(columnSizes);
    tree_free(tree);
}
