#include "SumRootToLeafNumbers.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SumRootToLeafNumbers, Solution129_1) {
  const auto Root1 = newTree({1, 2, 3});
  const int Expected1 = 25;
  EXPECT_EQ(Expected1, Solution129_1().sumNumbers(Root1));
  deleteTree(Root1);

  const auto Root2 = newTree({4, 9, 0, 5, 1});
  const int Expected2 = 1026;
  EXPECT_EQ(Expected2, Solution129_1().sumNumbers(Root2));
  deleteTree(Root2);
}
