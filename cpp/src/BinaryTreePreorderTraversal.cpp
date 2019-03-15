#include "BinaryTreePreorderTraversal.h"

using namespace lcpp;

static void preOrderTraversal(TreeNode *Root, std::vector<int> &Result) {
  if (Root == nullptr)
    return;
  Result.push_back(Root->val);
  preOrderTraversal(Root->left, Result);
  preOrderTraversal(Root->right, Result);
}

std::vector<int> Solution144_1::preorderTraversal(TreeNode *root) {
  std::vector<int> Result;
  preOrderTraversal(root, Result);
  return Result;
}
