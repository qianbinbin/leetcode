#include "UniqueBinarySearchTreesII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(UniqueBinarySearchTreesII, Solution95_1) {
  const int N = 3;
  const std::vector<TreeNode *> Expected{
      newTree({1, NTNode, 2, NTNode, 3}),
      newTree({1, NTNode, 3, 2}),
      newTree({2, 1, 3}),
      newTree({3, 1, NTNode, NTNode, 2}),
      newTree({3, 2, NTNode, 1})
  };
  const auto Actual = Solution95_1().generateTrees(N);
  ASSERT_EQ(Expected.size(), Actual.size());
  for (decltype(Expected.size()) I = 0, E = Expected.size(); I != E; ++I)
    EXPECT_EQ(*Expected[I], *Actual[I]);
  for (const auto &Root : Expected)
    deleteTree(Root);
  for (const auto &Root : Actual)
    deleteTree(Root);
}