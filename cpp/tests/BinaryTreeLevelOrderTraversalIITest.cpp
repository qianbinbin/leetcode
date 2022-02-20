#include "BinaryTreeLevelOrderTraversalII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(BinaryTreeLevelOrderTraversalII, Solution107_1) {
  auto S107_1 = Solution107_1();

  auto Root1 = newTree({3, 9, 20, NTNode, NTNode, 15, 7});
  std::vector<std::vector<int>> const Expected1{{15, 7}, {9, 20}, {3}};
  EXPECT_EQ(Expected1, S107_1.levelOrderBottom(Root1));
  deleteTree(Root1);

  auto Root2 = newTree({1});
  std::vector<std::vector<int>> const Expected2{{1}};
  EXPECT_EQ(Expected2, S107_1.levelOrderBottom(Root2));
  deleteTree(Root2);

  auto Root3 = newTree({});
  std::vector<std::vector<int>> const Expected3{};
  EXPECT_EQ(Expected3, S107_1.levelOrderBottom(Root3));
  deleteTree(Root3);
}

TEST(BinaryTreeLevelOrderTraversalII, Solution107_2) {
  auto S107_2 = Solution107_2();

  auto Root1 = newTree({3, 9, 20, NTNode, NTNode, 15, 7});
  std::vector<std::vector<int>> const Expected1{{15, 7}, {9, 20}, {3}};
  EXPECT_EQ(Expected1, S107_2.levelOrderBottom(Root1));
  deleteTree(Root1);

  auto Root2 = newTree({1});
  std::vector<std::vector<int>> const Expected2{{1}};
  EXPECT_EQ(Expected2, S107_2.levelOrderBottom(Root2));
  deleteTree(Root2);

  auto Root3 = newTree({});
  std::vector<std::vector<int>> const Expected3{};
  EXPECT_EQ(Expected3, S107_2.levelOrderBottom(Root3));
  deleteTree(Root3);
}