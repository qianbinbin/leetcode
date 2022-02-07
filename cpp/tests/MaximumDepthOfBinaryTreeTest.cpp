#include "MaximumDepthOfBinaryTree.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MaximumDepthOfBinaryTree, Solution104_1) {
  auto S104_1 = Solution104_1();

  auto Root1 = newTree({3, 9, 20, NTNode, NTNode, 15, 7});
  int const Expected1 = 3;
  EXPECT_EQ(Expected1, S104_1.maxDepth(Root1));
  deleteTree(Root1);

  auto Root2 = newTree({1, NTNode, 2});
  int const Expected2 = 2;
  EXPECT_EQ(Expected2, S104_1.maxDepth(Root2));
  deleteTree(Root2);
}