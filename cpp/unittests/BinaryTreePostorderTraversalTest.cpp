#include "BinaryTreePostorderTraversal.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(BinaryTreePostorderTraversal, Solution145_1) {
  const auto Root = newTree({1, NTNode, 2, 3});
  const std::vector<int> Expected{3, 2, 1};
  EXPECT_EQ(Expected, Solution145_1().postorderTraversal(Root));
  deleteTree(Root);
}