#include "ConvertSortedArrayToBinarySearchTree.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ConvertSortedArrayToBinarySearchTree, Solution108_1) {
  std::vector<int> Nums{-10, -3, 0, 5, 9};
  const auto Expected = newTree({0, -3, 9, -10, NTNode, 5}),
      Actual = Solution108_1().sortedArrayToBST(Nums);
  EXPECT_EQ(*Expected, *Actual);
  deleteTree(Expected);
  deleteTree(Actual);
}