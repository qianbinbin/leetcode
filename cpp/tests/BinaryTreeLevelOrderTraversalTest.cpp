#include "BinaryTreeLevelOrderTraversal.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(BinaryTreeLevelOrderTraversal, Solution102_1) {
  auto S102_1 = Solution102_1();

  auto Root1 = newTree({3, 9, 20, NTNode, NTNode, 15, 7});
  std::vector<std::vector<int>> const Expected1{{3}, {9, 20}, {15, 7}};
  EXPECT_EQ(Expected1, S102_1.levelOrder(Root1));
  deleteTree(Root1);

  auto Root2 = newTree({1});
  std::vector<std::vector<int>> const Expected2{{1}};
  EXPECT_EQ(Expected2, S102_1.levelOrder(Root2));
  deleteTree(Root2);

  auto Root3 = newTree({});
  std::vector<std::vector<int>> const Expected3{};
  EXPECT_EQ(Expected3, S102_1.levelOrder(Root3));
  deleteTree(Root3);
}

TEST(BinaryTreeLevelOrderTraversal, Solution102_2) {
  auto S102_2 = Solution102_2();

  auto Root1 = newTree({3, 9, 20, NTNode, NTNode, 15, 7});
  std::vector<std::vector<int>> const Expected1{{3}, {9, 20}, {15, 7}};
  EXPECT_EQ(Expected1, S102_2.levelOrder(Root1));
  deleteTree(Root1);

  auto Root2 = newTree({1});
  std::vector<std::vector<int>> const Expected2{{1}};
  EXPECT_EQ(Expected2, S102_2.levelOrder(Root2));
  deleteTree(Root2);

  auto Root3 = newTree({});
  std::vector<std::vector<int>> const Expected3{};
  EXPECT_EQ(Expected3, S102_2.levelOrder(Root3));
  deleteTree(Root3);
}
