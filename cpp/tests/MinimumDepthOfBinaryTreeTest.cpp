#include "MinimumDepthOfBinaryTree.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MinimumDepthOfBinaryTree, Solution111_1) {
  auto S111_1 = Solution111_1();

  auto Root1 = newTree({3, 9, 20, NTNode, NTNode, 15, 7});
  int const Expected1 = 2;
  EXPECT_EQ(Expected1, S111_1.minDepth(Root1));
  deleteTree(Root1);

  auto Root2 = newTree({2, NTNode, 3, NTNode, 4, NTNode, 5, NTNode, 6});
  int const Expected2 = 5;
  EXPECT_EQ(Expected2, S111_1.minDepth(Root2));
  deleteTree(Root2);
}

TEST(MinimumDepthOfBinaryTree, Solution111_2) {
  auto S111_2 = Solution111_2();

  auto Root1 = newTree({3, 9, 20, NTNode, NTNode, 15, 7});
  int const Expected1 = 2;
  EXPECT_EQ(Expected1, S111_2.minDepth(Root1));
  deleteTree(Root1);

  auto Root2 = newTree({2, NTNode, 3, NTNode, 4, NTNode, 5, NTNode, 6});
  int const Expected2 = 5;
  EXPECT_EQ(Expected2, S111_2.minDepth(Root2));
  deleteTree(Root2);
}
