#include <gtest/gtest.h>

extern "C" {
#include "unique_binary_search_trees.h"
}

TEST(unique_binary_search_trees_test, numTrees_96_1) {
    EXPECT_EQ(numTrees_96_1(3), 5);
}

TEST(unique_binary_search_trees_test, numTrees_96_2) {
    EXPECT_EQ(numTrees_96_2(3), 5);
}
