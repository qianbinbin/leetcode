#include "PathSum.h"

using namespace lcpp;

bool Solution112_1::hasPathSum(TreeNode *root, int targetSum) {
  if (root == nullptr)
    return false;
  if (root->left == nullptr && root->right == nullptr)
    return root->val == targetSum;
  return hasPathSum(root->left, targetSum - root->val) ||
         hasPathSum(root->right, targetSum - root->val);
}
