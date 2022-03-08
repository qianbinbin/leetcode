#include <gtest/gtest.h>

extern "C" {
#include "palindrome_partitioning_ii.h"
}

TEST(palindrome_partitioning_ii_test, minCut_132_1) {
    EXPECT_EQ(1, minCut_132_1("aab"));
    EXPECT_EQ(0, minCut_132_1("a"));
    EXPECT_EQ(1, minCut_132_1("ab"));
}

TEST(palindrome_partitioning_ii_test, minCut_132_2) {
    EXPECT_EQ(1, minCut_132_2("aab"));
    EXPECT_EQ(0, minCut_132_2("a"));
    EXPECT_EQ(1, minCut_132_2("ab"));
}
