#include "PalindromePartitioningII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(PalindromePartitioningII, Solution132_1) {
  EXPECT_EQ(1, Solution132_1().minCut("aab"));
}