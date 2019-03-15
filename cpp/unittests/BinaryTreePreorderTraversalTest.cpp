#include "BinaryTreePreorderTraversal.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(BinaryTreePreorderTraversal, Solution144_1) {
  const auto Root = newTree({1, NTNode, 2, 3});
  const std::vector<int> Expected{1, 2, 3};
  EXPECT_EQ(Expected, Solution144_1().preorderTraversal(Root));
  deleteTree(Root);
}