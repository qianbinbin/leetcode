#include "BinaryTreePostorderTraversal.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(BinaryTreePostorderTraversal, Solution145_1) {
  auto S145_1 = Solution145_1();

  auto Root1 = newTree({1, NTNode, 2, 3});
  std::vector<int> const Expected1{3, 2, 1};
  EXPECT_EQ(Expected1, S145_1.postorderTraversal(Root1));
  deleteTree(Root1);

  auto Root2 = newTree({});
  std::vector<int> const Expected2;
  EXPECT_EQ(Expected2, S145_1.postorderTraversal(Root2));
  deleteTree(Root2);

  auto Root3 = newTree({1});
  std::vector<int> const Expected3{1};
  EXPECT_EQ(Expected3, S145_1.postorderTraversal(Root3));
  deleteTree(Root3);
}

TEST(BinaryTreePostorderTraversal, Solution145_2) {
  auto S145_2 = Solution145_2();

  auto Root1 = newTree({1, NTNode, 2, 3});
  std::vector<int> const Expected1{3, 2, 1};
  EXPECT_EQ(Expected1, S145_2.postorderTraversal(Root1));
  deleteTree(Root1);

  auto Root2 = newTree({});
  std::vector<int> const Expected2;
  EXPECT_EQ(Expected2, S145_2.postorderTraversal(Root2));
  deleteTree(Root2);

  auto Root3 = newTree({1});
  std::vector<int> const Expected3{1};
  EXPECT_EQ(Expected3, S145_2.postorderTraversal(Root3));
  deleteTree(Root3);
}

TEST(BinaryTreePostorderTraversal, Solution145_3) {
  auto S145_3 = Solution145_3();

  auto Root1 = newTree({1, NTNode, 2, 3});
  std::vector<int> const Expected1{3, 2, 1};
  EXPECT_EQ(Expected1, S145_3.postorderTraversal(Root1));
  deleteTree(Root1);

  auto Root2 = newTree({});
  std::vector<int> const Expected2;
  EXPECT_EQ(Expected2, S145_3.postorderTraversal(Root2));
  deleteTree(Root2);

  auto Root3 = newTree({1});
  std::vector<int> const Expected3{1};
  EXPECT_EQ(Expected3, S145_3.postorderTraversal(Root3));
  deleteTree(Root3);
}
