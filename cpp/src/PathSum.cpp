#include "PathSum.h"

using namespace lcpp;

static bool hasPathSum(TreeNode *Root, int Sum) {
  Sum -= Root->val;
  if (Root->left == nullptr && Root->right == nullptr)
    return Sum == 0;
  if (Root->left != nullptr && hasPathSum(Root->left, Sum))
    return true;
  return Root->right != nullptr && hasPathSum(Root->right, Sum);
}

bool Solution112_1::hasPathSum(TreeNode *root, int sum) {
  if (root == nullptr)
    return false;
  return ::hasPathSum(root, sum);
}
