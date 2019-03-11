#include "BinaryTreeInorderTraversal.h"

using namespace lcpp;

static void inOrderTraversal(TreeNode *Root, std::vector<int> &Result) {
  if (Root == nullptr)
    return;
  inOrderTraversal(Root->left, Result);
  Result.push_back(Root->val);
  inOrderTraversal(Root->right, Result);
}

std::vector<int> Solution94_1::inorderTraversal(TreeNode *root) {
  std::vector<int> Result;
  inOrderTraversal(root, Result);
  return Result;
}
