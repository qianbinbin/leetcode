#include <gtest/gtest.h>

extern "C" {
#include <binary_tree_level_order_traversal.h>
}

TEST(leetcode_102, normal) {
    int nums[] = {3, 9, 20, NTNODE, NTNODE, 15, 7};
    struct TreeNode *tree = tree_create(nums, 7);
    int size = 0;
    int *columnSizes = (int *) malloc(sizeof(int));
    int **ret = levelOrder_102(tree, &columnSizes, &size);
    for (int i = 0; i < size; ++i) {
        array_print(ret[i], columnSizes[i]);
        free(ret[i]);
    }
    free(ret);
    free(columnSizes);
    tree_free(tree);
}
