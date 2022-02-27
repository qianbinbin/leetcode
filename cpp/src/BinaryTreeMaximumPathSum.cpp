#include "BinaryTreeMaximumPathSum.h"
#include <algorithm>

using namespace lcpp;

static int maxSinglePathSum(TreeNode *Root, int &MaxPathSum) {
  if (Root == nullptr)
    return 0;
  int Left = std::max(0, maxSinglePathSum(Root->left, MaxPathSum)),
      Right = std::max(0, maxSinglePathSum(Root->right, MaxPathSum));
  MaxPathSum = std::max(MaxPathSum, Left + Right + Root->val);
  return std::max(Left, Right) + Root->val;
}

int Solution124_1::maxPathSum(TreeNode *root) {
  int Result = root->val;
  ::maxSinglePathSum(root, Result);
  return Result;
}
