#include "ConstructBinaryTreeFromPreorderAndInorderTraversal.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ConstructBinaryTreeFromPreorderAndInorderTraversal, Solution105_1) {
  std::vector<int> PreOrder{3, 9, 20, 15, 7}, InOrder{9, 3, 15, 20, 7};
  const auto Expected = newTree({3, 9, 20, NTNode, NTNode, 15, 7}),
      Actual = Solution105_1().buildTree(PreOrder, InOrder);
  EXPECT_EQ(*Expected, *Actual);
  deleteTree(Expected);
  deleteTree(Actual);
}