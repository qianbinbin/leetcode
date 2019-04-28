#include "LowestCommonAncestorOfABinaryTree.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(LowestCommonAncestorOfABinaryTree, Solution236_1) {
  const auto Root1 = newTree({3, 5, 1, 6, 2, 0, 8, NTNode, NTNode, 7, 4});
  const auto &P1 = Root1->left, &Q1 = Root1->right, &Expected1 = Root1;
  EXPECT_EQ(Expected1, Solution236_1().lowestCommonAncestor(Root1, P1, Q1));
  deleteTree(Root1);

  const auto Root2 = newTree({3, 5, 1, 6, 2, 0, 8, NTNode, NTNode, 7, 4});
  const auto &P2 = Root2->left, &Q2 = Root2->left->right->right,
             &Expected2 = P2;
  EXPECT_EQ(Expected2, Solution236_1().lowestCommonAncestor(Root2, P2, Q2));
  deleteTree(Root2);
}

TEST(LowestCommonAncestorOfABinaryTree, Solution236_2) {
  const auto Root1 = newTree({3, 5, 1, 6, 2, 0, 8, NTNode, NTNode, 7, 4});
  const auto &P1 = Root1->left, &Q1 = Root1->right, &Expected1 = Root1;
  EXPECT_EQ(Expected1, Solution236_2().lowestCommonAncestor(Root1, P1, Q1));
  deleteTree(Root1);

  const auto Root2 = newTree({3, 5, 1, 6, 2, 0, 8, NTNode, NTNode, 7, 4});
  const auto &P2 = Root2->left, &Q2 = Root2->left->right->right,
             &Expected2 = P2;
  EXPECT_EQ(Expected2, Solution236_2().lowestCommonAncestor(Root2, P2, Q2));
  deleteTree(Root2);
}

TEST(LowestCommonAncestorOfABinaryTree, Solution236_3) {
  const auto Root1 = newTree({3, 5, 1, 6, 2, 0, 8, NTNode, NTNode, 7, 4});
  const auto &P1 = Root1->left, &Q1 = Root1->right, &Expected1 = Root1;
  EXPECT_EQ(Expected1, Solution236_3().lowestCommonAncestor(Root1, P1, Q1));
  deleteTree(Root1);

  const auto Root2 = newTree({3, 5, 1, 6, 2, 0, 8, NTNode, NTNode, 7, 4});
  const auto &P2 = Root2->left, &Q2 = Root2->left->right->right,
             &Expected2 = P2;
  EXPECT_EQ(Expected2, Solution236_3().lowestCommonAncestor(Root2, P2, Q2));
  deleteTree(Root2);
}
