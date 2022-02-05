#include "BinaryTreeZigzagLevelOrderTraversal.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(BinaryTreeZigzagLevelOrderTraversal, Solution103_1) {
  auto S103_1 = Solution103_1();

  auto Root1 = newTree({3, 9, 20, NTNode, NTNode, 15, 7});
  std::vector<std::vector<int>> const Expected1{{3}, {20, 9}, {15, 7}};
  EXPECT_EQ(Expected1, S103_1.zigzagLevelOrder(Root1));
  deleteTree(Root1);

  auto Root2 = newTree({1});
  std::vector<std::vector<int>> const Expected2{{1}};
  EXPECT_EQ(Expected2, S103_1.zigzagLevelOrder(Root2));
  deleteTree(Root2);

  auto Root3 = newTree({});
  std::vector<std::vector<int>> const Expected3{};
  EXPECT_EQ(Expected3, S103_1.zigzagLevelOrder(Root3));
  deleteTree(Root3);
}

TEST(BinaryTreeZigzagLevelOrderTraversal, Solution103_2) {
  auto S103_2 = Solution103_2();

  auto Root1 = newTree({3, 9, 20, NTNode, NTNode, 15, 7});
  std::vector<std::vector<int>> const Expected1{{3}, {20, 9}, {15, 7}};
  EXPECT_EQ(Expected1, S103_2.zigzagLevelOrder(Root1));
  deleteTree(Root1);

  auto Root2 = newTree({1});
  std::vector<std::vector<int>> const Expected2{{1}};
  EXPECT_EQ(Expected2, S103_2.zigzagLevelOrder(Root2));
  deleteTree(Root2);

  auto Root3 = newTree({});
  std::vector<std::vector<int>> const Expected3{};
  EXPECT_EQ(Expected3, S103_2.zigzagLevelOrder(Root3));
  deleteTree(Root3);
}
