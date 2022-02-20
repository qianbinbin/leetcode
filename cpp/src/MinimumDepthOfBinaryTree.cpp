#include "MinimumDepthOfBinaryTree.h"
#include <algorithm>
#include <queue>

using namespace lcpp;

int Solution111_1::minDepth(TreeNode *root) {
  if (root == nullptr)
    return 0;
  int left = minDepth(root->left), right = minDepth(root->right);
  if (left == 0)
    return right + 1;
  if (right == 0)
    return left + 1;
  return std::min(left, right) + 1;
}

int Solution111_2::minDepth(TreeNode *root) {
  if (root == nullptr)
    return 0;
  std::queue<TreeNode *> Queue;
  int Depth = 1;
  Queue.push(root);
  while (!Queue.empty()) {
    for (auto I = Queue.size(); I != 0; --I) {
      auto Node = Queue.front();
      Queue.pop();
      if (Node->left == nullptr && Node->right == nullptr)
        return Depth;
      if (Node->left != nullptr)
        Queue.push(Node->left);
      if (Node->right != nullptr)
        Queue.push(Node->right);
    }
    ++Depth;
  }
  return Depth;
}
