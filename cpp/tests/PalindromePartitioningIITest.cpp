#include "PalindromePartitioningII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(PalindromePartitioningII, Solution132_1) {
  auto S132_1 = Solution132_1();

  EXPECT_EQ(1, S132_1.minCut("aab"));
  EXPECT_EQ(0, S132_1.minCut("a"));
  EXPECT_EQ(1, S132_1.minCut("ab"));
}

TEST(PalindromePartitioningII, Solution132_2) {
  auto S132_2 = Solution132_2();

  EXPECT_EQ(1, S132_2.minCut("aab"));
  EXPECT_EQ(0, S132_2.minCut("a"));
  EXPECT_EQ(1, S132_2.minCut("ab"));
}
