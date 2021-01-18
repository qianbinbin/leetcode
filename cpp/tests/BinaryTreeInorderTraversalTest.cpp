#include "BinaryTreeInorderTraversal.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(BinaryTreeInorderTraversal, Solution94_1) {
  const auto Root = newTree({1, NTNode, 2, 3});
  const std::vector<int> Expected{1, 3, 2};
  EXPECT_EQ(Expected, Solution94_1().inorderTraversal(Root));
  deleteTree(Root);
}

TEST(BinaryTreeInorderTraversal, Solution94_2) {
  const auto Root = newTree({1, NTNode, 2, 3});
  const std::vector<int> Expected{1, 3, 2};
  EXPECT_EQ(Expected, Solution94_2().inorderTraversal(Root));
  deleteTree(Root);
}
