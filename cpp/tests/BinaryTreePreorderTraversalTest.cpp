#include "BinaryTreePreorderTraversal.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(BinaryTreePreorderTraversal, Solution144_1) {
  auto S144_1 = Solution144_1();

  auto Root1 = newTree({1, NTNode, 2, 3});
  std::vector<int> const Expected1{1, 2, 3};
  EXPECT_EQ(Expected1, S144_1.preorderTraversal(Root1));
  deleteTree(Root1);

  auto Root2 = newTree({});
  std::vector<int> const Expected2;
  EXPECT_EQ(Expected2, S144_1.preorderTraversal(Root2));
  deleteTree(Root2);

  auto Root3 = newTree({1});
  std::vector<int> const Expected3{1};
  EXPECT_EQ(Expected3, S144_1.preorderTraversal(Root3));
  deleteTree(Root3);
}

TEST(BinaryTreePreorderTraversal, Solution144_2) {
  auto S144_2 = Solution144_2();

  auto Root1 = newTree({1, NTNode, 2, 3});
  std::vector<int> const Expected1{1, 2, 3};
  EXPECT_EQ(Expected1, S144_2.preorderTraversal(Root1));
  deleteTree(Root1);

  auto Root2 = newTree({});
  std::vector<int> const Expected2;
  EXPECT_EQ(Expected2, S144_2.preorderTraversal(Root2));
  deleteTree(Root2);

  auto Root3 = newTree({1});
  std::vector<int> const Expected3{1};
  EXPECT_EQ(Expected3, S144_2.preorderTraversal(Root3));
  deleteTree(Root3);
}
