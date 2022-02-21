#include "PathSum.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(PathSum, Solution112_1) {
  auto S112_1 = Solution112_1();

  auto Root1 =
      newTree({5, 4, 8, 11, NTNode, 13, 4, 7, 2, NTNode, NTNode, NTNode, 1});
  int const Sum1 = 22;
  EXPECT_TRUE(S112_1.hasPathSum(Root1, Sum1));
  deleteTree(Root1);

  auto Root2 = newTree({1, 2, 3});
  int const Sum2 = 5;
  EXPECT_FALSE(S112_1.hasPathSum(Root2, Sum2));
  deleteTree(Root2);

  auto Root3 = newTree({});
  int const Sum3 = 0;
  EXPECT_FALSE(S112_1.hasPathSum(Root3, Sum3));
  deleteTree(Root3);
}