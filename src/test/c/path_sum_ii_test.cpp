#include <gtest/gtest.h>

extern "C" {
#include <path_sum_ii.h>
}

TEST(leetcode_113, normal) {
    int nums[] = {5, 4, 8, 11, NTNODE, 13, 4, 7, 2, NTNODE, NTNODE,
                  NTNODE, NTNODE, 5, 1};
    struct TreeNode *tree = tree_create(nums, sizeof(nums) / sizeof(nums[0]));
    tree_preorder_print(tree);
    tree_inorder_print(tree);
    int *column_sizes = NULL;
    int size = 0;
    int **ret = pathSum_113(tree, 22, &column_sizes, &size);
    for (int i = 0; i < size; ++i) {
        array_print(ret[i], column_sizes[i]);
        free(ret[i]);
    }
    free(column_sizes);
    tree_free(tree);
}
