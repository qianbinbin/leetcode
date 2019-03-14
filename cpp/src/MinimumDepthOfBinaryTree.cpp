#include "MinimumDepthOfBinaryTree.h"
#include <algorithm>

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
