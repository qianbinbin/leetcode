#include "BinaryTreePostorderTraversal.h"

using namespace lcpp;

static void postOrderTraversal(TreeNode *Root, std::vector<int> &Result) {
  if (Root == nullptr)
    return;
  postOrderTraversal(Root->left, Result);
  postOrderTraversal(Root->right, Result);
  Result.push_back(Root->val);
}

std::vector<int> Solution145_1::postorderTraversal(TreeNode *root) {
  std::vector<int> Result;
  postOrderTraversal(root, Result);
  return Result;
}
