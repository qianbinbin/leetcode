#include "UniqueBinarySearchTrees.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(UniqueBinarySearchTrees, Solution96_1) {
  const int N = 3;
  const int Expected = 5;
  EXPECT_EQ(Expected, Solution96_1().numTrees(N));
}
