#include <gtest/gtest.h>

extern "C" {
#include <binary-tree-level-order-traversal-ii.h>
}

TEST(leetcode_107, normal) {
    int nums[] = {3, 9, 20, INT_NULL_TREE_NODE, INT_NULL_TREE_NODE, 15, 7};
    struct TreeNode *tree = tree_create(nums, 7);
    int size = 0;
    int *columnSizes = (int *) malloc(sizeof(int));
    int **ret = levelOrderBottom_107(tree, &columnSizes, &size);
    for (int i = 0; i < size; ++i) {
        print_array(ret[i], columnSizes[i]);
        free(ret[i]);
    }
    free(ret);
    free(columnSizes);
    tree_free(tree);
}
