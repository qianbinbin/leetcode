#include "MaximumDepthOfBinaryTree.h"
#include <algorithm>

using namespace lcpp;

int Solution104_1::maxDepth(TreeNode *root) {
  if (root == nullptr)
    return 0;
  return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
