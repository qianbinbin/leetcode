#include "ConstructBinaryTreeFromInorderAndPostorderTraversal.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ConstructBinaryTreeFromInorderAndPostorderTraversal, Solution106_1) {
  std::vector<int> InOrder{9, 3, 15, 20, 7}, PostOrder{9, 15, 7, 20, 3};
  const auto Expected = newTree({3, 9, 20, NTNode, NTNode, 15, 7}),
      Actual = Solution106_1().buildTree(InOrder, PostOrder);
  EXPECT_EQ(*Expected, *Actual);
  deleteTree(Expected);
  deleteTree(Actual);
}