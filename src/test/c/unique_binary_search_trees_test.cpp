#include <gtest/gtest.h>

extern "C" {
#include <unique_binary_search_trees.h>
}

TEST(leetcode_96, normal) {
    EXPECT_EQ(numTrees_96(5), 42);
}
