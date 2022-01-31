#include "BinaryTreeInorderTraversal.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(BinaryTreeInorderTraversal, Solution94_1) {
  auto S94_1 = Solution94_1();

  auto Root1 = newTree({1, NTNode, 2, 3});
  std::vector<int> const Expected1{1, 3, 2};
  EXPECT_EQ(Expected1, S94_1.inorderTraversal(Root1));
  deleteTree(Root1);

  auto Root2 = newTree({});
  std::vector<int> const Expected2{};
  EXPECT_EQ(Expected2, S94_1.inorderTraversal(Root2));
  deleteTree(Root2);

  auto Root3 = newTree({1});
  std::vector<int> const Expected3{1};
  EXPECT_EQ(Expected3, S94_1.inorderTraversal(Root3));
  deleteTree(Root3);
}

TEST(BinaryTreeInorderTraversal, Solution94_2) {
  auto S94_2 = Solution94_2();

  auto Root1 = newTree({1, NTNode, 2, 3});
  std::vector<int> const Expected1{1, 3, 2};
  EXPECT_EQ(Expected1, S94_2.inorderTraversal(Root1));
  deleteTree(Root1);

  auto Root2 = newTree({});
  std::vector<int> const Expected2{};
  EXPECT_EQ(Expected2, S94_2.inorderTraversal(Root2));
  deleteTree(Root2);

  auto Root3 = newTree({1});
  std::vector<int> const Expected3{1};
  EXPECT_EQ(Expected3, S94_2.inorderTraversal(Root3));
  deleteTree(Root3);
}
