#include "BinaryTreeLevelOrderTraversalII.h"
#include <algorithm>
#include <queue>

using namespace lcpp;

template <typename T> using TwoDimVec = std::vector<std::vector<T>>;

using SizeType = TwoDimVec<int>::size_type;

static void preOrder(TreeNode *Root, SizeType Level, TwoDimVec<int> &Result) {
  if (Root == nullptr)
    return;
  if (Level == Result.size())
    Result.emplace_back();
  Result[Level].push_back(Root->val);
  preOrder(Root->left, Level + 1, Result);
  preOrder(Root->right, Level + 1, Result);
}

std::vector<std::vector<int>> Solution107_1::levelOrderBottom(TreeNode *root) {
  TwoDimVec<int> Result;
  ::preOrder(root, 0, Result);
  std::reverse(Result.begin(), Result.end());
  return Result;
}

std::vector<std::vector<int>> Solution107_2::levelOrderBottom(TreeNode *root) {
  std::vector<std::vector<int>> Result;
  if (root == nullptr)
    return Result;
  std::queue<TreeNode *> Queue;
  Queue.push(root);
  while (!Queue.empty()) {
    Result.emplace_back();
    auto &Level = Result.back();
    for (auto I = Queue.size(); I != 0; --I) {
      auto Node = Queue.front();
      Queue.pop();
      Level.push_back(Node->val);
      if (Node->left != nullptr)
        Queue.push(Node->left);
      if (Node->right != nullptr)
        Queue.push(Node->right);
    }
  }
  std::reverse(Result.begin(), Result.end());
  return Result;
}
