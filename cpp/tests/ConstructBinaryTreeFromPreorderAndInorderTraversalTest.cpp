#include "ConstructBinaryTreeFromPreorderAndInorderTraversal.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ConstructBinaryTreeFromPreorderAndInorderTraversal, Solution105_1) {
  auto S105_1 = Solution105_1();

  std::vector<int> PreOrder1{3, 9, 20, 15, 7}, InOrder1{9, 3, 15, 20, 7};
  auto Expected1 = newTree({3, 9, 20, NTNode, NTNode, 15, 7});
  auto Actual1 = S105_1.buildTree(PreOrder1, InOrder1);
  EXPECT_EQ(*Expected1, *Actual1);
  deleteTree(Expected1);
  deleteTree(Actual1);

  std::vector<int> PreOrder2{-1}, InOrder2{-1};
  auto Expected2 = newTree({-1});
  auto Actual2 = S105_1.buildTree(PreOrder2, InOrder2);
  EXPECT_EQ(*Expected2, *Actual2);
  deleteTree(Expected2);
  deleteTree(Actual2);
}