#include "BinaryTreePostorderTraversal.h"
#include <algorithm>
#include <stack>

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

std::vector<int> Solution145_2::postorderTraversal(TreeNode *root) {
  std::vector<int> Result;
  if (root == nullptr)
    return Result;
  std::stack<TreeNode *> Stack;
  Stack.push(root);
  while (!Stack.empty()) {
    auto Node = Stack.top();
    Stack.pop();
    if (Node->left != nullptr)
      Stack.push(Node->left);
    if (Node->right != nullptr)
      Stack.push(Node->right);
    Result.push_back(Node->val);
  }
  std::reverse(Result.begin(), Result.end());
  return Result;
}

std::vector<int> Solution145_3::postorderTraversal(TreeNode *root) {
  std::vector<int> Result;
  TreeNode *Node = root, *Pre = nullptr;
  std::stack<TreeNode *> Stack;
  while (Node != nullptr || !Stack.empty()) {
    if (Node != nullptr) {
      Stack.push(Node);
      Node = Node->left;
    } else {
      Node = Stack.top();
      if (Node->right == nullptr || Node->right == Pre) {
        Result.push_back(Node->val);
        Pre = Node;
        Stack.pop();
        Node = nullptr;
      } else {
        Node = Node->right;
      }
    }
  }
  return Result;
}
