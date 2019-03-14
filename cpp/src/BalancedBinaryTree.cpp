#include "BalancedBinaryTree.h"
#include <algorithm>
#include <cstddef>

using namespace lcpp;

#define ABS(A, B) ((A) >= (B) ? (A) - (B) : (B) - (A))

static std::size_t depth(TreeNode *Root, bool &IsBalanced) {
  if (Root == nullptr)
    return 0;
  auto LeftDepth = depth(Root->left, IsBalanced),
      RightDepth = depth(Root->right, IsBalanced);
  if (IsBalanced
      && ABS(LeftDepth, RightDepth) > 1)
    IsBalanced = false;
  return std::max(LeftDepth, RightDepth) + 1;
}

bool Solution110_1::isBalanced(TreeNode *root) {
  bool IsBalanced = true;
  depth(root, IsBalanced);
  return IsBalanced;
}
