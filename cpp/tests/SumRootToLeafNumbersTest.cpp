#include "SumRootToLeafNumbers.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SumRootToLeafNumbers, Solution129_1) {
  auto S129_1 = Solution129_1();

  auto Root1 = newTree({1, 2, 3});
  int const Expected1 = 25;
  EXPECT_EQ(Expected1, S129_1.sumNumbers(Root1));
  deleteTree(Root1);

  auto Root2 = newTree({4, 9, 0, 5, 1});
  int const Expected2 = 1026;
  EXPECT_EQ(Expected2, S129_1.sumNumbers(Root2));
  deleteTree(Root2);
}
