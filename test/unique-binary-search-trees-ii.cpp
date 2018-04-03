#include <gtest/gtest.h>

extern "C" {
#include <unique-binary-search-trees-ii.h>
}

TEST(leetcode_95, normal) {
    int size = 0;
    struct TreeNode **trees = generateTrees_95(4, &size);
    for (int i = 0; i < size; ++i) {
        tree_preorder_print(trees[i]);
        tree_free(trees[i]);
    }
    free(trees);
}
