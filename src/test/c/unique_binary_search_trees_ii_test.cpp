#include <gtest/gtest.h>

extern "C" {
#include "unique_binary_search_trees_ii.h"
}

TEST(unique_binary_search_trees_ii_test, generateTrees_95_1) {
    int size = 0;
    struct TreeNode **trees = generateTrees_95_1(3, &size);
    for (int i = 0; i < size; ++i) {
        tree_preorder_print(trees[i]);
        tree_free(trees[i]);
    }
    free(trees);
}
