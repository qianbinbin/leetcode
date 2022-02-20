#include "ConvertSortedArrayToBinarySearchTree.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ConvertSortedArrayToBinarySearchTree, Solution108_1) {
  auto S108_1 = Solution108_1();

  std::vector<int> Nums1{-10, -3, 0, 5, 9};
  auto Expected1 = newTree({0, -3, 9, -10, NTNode, 5});
  auto Actual1 = S108_1.sortedArrayToBST(Nums1);
  EXPECT_EQ(*Expected1, *Actual1);
  deleteTree(Expected1);
  deleteTree(Actual1);

  std::vector<int> Nums2{1, 3};
  auto Expected2 = newTree({3, 1});
  auto Actual2 = S108_1.sortedArrayToBST(Nums2);
  EXPECT_EQ(*Expected2, *Actual2);
  deleteTree(Expected2);
  deleteTree(Actual2);
}