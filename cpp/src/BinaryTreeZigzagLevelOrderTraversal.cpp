#include "BinaryTreeZigzagLevelOrderTraversal.h"
#include <algorithm>

using namespace lcpp;

template<typename T> using TwoDimVec = std::vector<std::vector<T>>;

using SizeType = TwoDimVec<int>::size_type;

static void preOrder(TreeNode *Root, SizeType Level, TwoDimVec<int> &Result) {
  if (Root == nullptr)
    return;
  if (Level == Result.size())
    Result.push_back({});
  Result[Level].push_back(Root->val);
  preOrder(Root->left, Level + 1, Result);
  preOrder(Root->right, Level + 1, Result);
}

std::vector<std::vector<int>> Solution103_1::zigzagLevelOrder(TreeNode *root) {
  TwoDimVec<int> Result;
  preOrder(root, 0, Result);
  for (SizeType I = 1, E = Result.size(); I < E; I += 2)
    std::reverse(Result[I].begin(), Result[I].end());
  return Result;
}
