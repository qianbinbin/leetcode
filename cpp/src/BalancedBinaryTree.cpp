#include "BalancedBinaryTree.h"
#include <algorithm>
#include <cstdlib>

using namespace lcpp;

static int depth(TreeNode *Root) {
  if (Root == nullptr)
    return 0;
  int Left = depth(Root->left);
  if (Left == -1)
    return -1;
  int Right = depth(Root->right);
  if (Right == -1)
    return -1;
  if (std::abs(Left - Right) > 1)
    return -1;
  return std::max(Left, Right) + 1;
}

bool Solution110_1::isBalanced(TreeNode *root) { return depth(root) != -1; }
