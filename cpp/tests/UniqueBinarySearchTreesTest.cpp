#include "UniqueBinarySearchTrees.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(UniqueBinarySearchTrees, Solution96_1) {
  auto S96_1 = Solution96_1();

  EXPECT_EQ(5, S96_1.numTrees(3));
  EXPECT_EQ(1, S96_1.numTrees(1));
}

TEST(UniqueBinarySearchTrees, Solution96_2) {
  auto S96_2 = Solution96_2();

  EXPECT_EQ(5, S96_2.numTrees(3));
  EXPECT_EQ(1, S96_2.numTrees(1));
}
