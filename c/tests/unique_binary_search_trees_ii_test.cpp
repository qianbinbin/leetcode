#include <gtest/gtest.h>

extern "C" {
#include "unique_binary_search_trees_ii.h"
}

TEST(unique_binary_search_trees_ii_test, generateTrees_95_1) {
    int const n1 = 3;
    int returnSize1 = 0;
    struct TreeNode **actual1 = generateTrees_95_1(n1, &returnSize1);
    for (int i = 0; i < returnSize1; ++i) {
        tree_preorder_print(actual1[i]);
        tree_free(actual1[i]);
    }
    free(actual1);

    int const n2 = 1;
    int returnSize2 = 0;
    struct TreeNode **actual2 = generateTrees_95_1(n2, &returnSize2);
    for (int i = 0; i < returnSize2; ++i) {
        tree_preorder_print(actual2[i]);
        tree_free(actual2[i]);
    }
    free(actual2);
}
