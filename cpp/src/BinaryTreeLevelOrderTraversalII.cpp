#include "BinaryTreeLevelOrderTraversalII.h"
#include <algorithm>
#include <queue>

using namespace lcpp;

std::vector<std::vector<int>> Solution107_1::levelOrderBottom(TreeNode *root) {
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
