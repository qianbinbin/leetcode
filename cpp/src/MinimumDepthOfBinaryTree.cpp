#include "MinimumDepthOfBinaryTree.h"
#include <algorithm>
#include <queue>

using namespace lcpp;

int Solution111_1::minDepth(TreeNode *root) {
  if (root == nullptr)
    return 0;
  if (root->left == nullptr)
    return minDepth(root->right) + 1;
  if (root->right == nullptr)
    return minDepth(root->left) + 1;
  return std::min(minDepth(root->left), minDepth(root->right)) + 1;
}

int Solution111_2::minDepth(TreeNode *root) {
  if (root == nullptr)
    return 0;
  int Depth = 0;
  bool Stop = false;
  std::queue<TreeNode *> Queue;
  Queue.push(root);
  while (!Stop && !Queue.empty()) {
    ++Depth;
    for (auto I = Queue.size(); I != 0; --I) {
      auto Node = Queue.front();
      Queue.pop();
      if (Node->left == nullptr && Node->right == nullptr) {
        Stop = true;
        break;
      }
      if (Node->left != nullptr)
        Queue.push(Node->left);
      if (Node->right != nullptr)
        Queue.push(Node->right);
    }
  }
  return Depth;
}
