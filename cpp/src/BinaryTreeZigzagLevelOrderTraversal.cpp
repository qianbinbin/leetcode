#include "BinaryTreeZigzagLevelOrderTraversal.h"
#include <algorithm>
#include <queue>

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

std::vector<std::vector<int>> Solution103_2::zigzagLevelOrder(TreeNode *root) {
  TwoDimVec<int> Result;
  if (root == nullptr)
    return Result;
  std::queue<TreeNode *> Queue;
  Queue.push(root);
  bool Reverse = false;
  while (!Queue.empty()) {
    Result.push_back({});
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
    if (Reverse)
      std::reverse(Level.begin(), Level.end());
    Reverse = !Reverse;
  }
  return Result;
}
