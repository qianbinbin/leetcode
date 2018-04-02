#include <gtest/gtest.h>

extern "C" {
#include <unique-binary-search-trees.h>
}

TEST(leetcode_96, normal) {
    EXPECT_EQ(numTrees_96(5), 42);
}
