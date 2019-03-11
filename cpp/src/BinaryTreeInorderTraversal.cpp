#include "BinaryTreeInorderTraversal.h"
#include <stack>

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

std::vector<int> Solution94_2::inorderTraversal(TreeNode *root) {
  std::vector<int> Result;
  if (root == nullptr)
    return Result;
  std::stack<TreeNode *> Stack;
  auto Node = root;
  while (Node != nullptr || !Stack.empty()) {
    if (Node != nullptr) {
      Stack.push(Node);
      Node = Node->left;
    } else {
      Node = Stack.top();
      Stack.pop();
      Result.push_back(Node->val);
      Node = Node->right;
    }
  }
  return Result;
}
