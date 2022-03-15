#include "BinaryTreePreorderTraversal.h"
#include <stack>

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

std::vector<int> Solution144_2::preorderTraversal(TreeNode *root) {
  std::vector<int> Result;
  if (root == nullptr)
    return Result;
  std::stack<TreeNode *> Stack;
  Stack.push(root);
  while (!Stack.empty()) {
    auto Node = Stack.top();
    Stack.pop();
    Result.push_back(Node->val);
    if (Node->right != nullptr)
      Stack.push(Node->right);
    if (Node->left != nullptr)
      Stack.push(Node->left);
  }
  return Result;
}
