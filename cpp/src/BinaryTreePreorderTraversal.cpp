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
  std::stack<TreeNode *> Stack;
  auto Node = root;
  while (Node != nullptr || !Stack.empty()) {
    if (Node != nullptr) {
      Result.push_back(Node->val);
      Stack.push(Node);
      Node = Node->left;
    } else {
      Node = Stack.top()->right;
      Stack.pop();
    }
  }
  return Result;
}
