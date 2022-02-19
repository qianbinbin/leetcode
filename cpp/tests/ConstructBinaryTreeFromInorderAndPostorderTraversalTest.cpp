#include "ConstructBinaryTreeFromInorderAndPostorderTraversal.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ConstructBinaryTreeFromInorderAndPostorderTraversal, Solution106_1) {
  auto S106_1 = Solution106_1();

  std::vector<int> InOrder1{9, 3, 15, 20, 7}, PostOrder1{9, 15, 7, 20, 3};
  auto Expected1 = newTree({3, 9, 20, NTNode, NTNode, 15, 7});
  auto Actual1 = S106_1.buildTree(InOrder1, PostOrder1);
  EXPECT_EQ(*Expected1, *Actual1);
  deleteTree(Expected1);
  deleteTree(Actual1);

  std::vector<int> InOrder2{-1}, PostOrder2{-1};
  auto Expected2 = newTree({-1});
  auto Actual2 = S106_1.buildTree(InOrder2, PostOrder2);
  EXPECT_EQ(*Expected2, *Actual2);
  deleteTree(Expected2);
  deleteTree(Actual2);
}