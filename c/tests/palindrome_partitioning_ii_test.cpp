#include <gtest/gtest.h>

extern "C" {
#include "palindrome_partitioning_ii.h"
}

TEST(palindrome_partitioning_ii_test, minCut_132_1) {
    EXPECT_EQ(minCut_132_1("aab"), 1);
}

TEST(palindrome_partitioning_ii_test, minCut_132_2) {
    EXPECT_EQ(minCut_132_2("aab"), 1);
}
