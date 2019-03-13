#include "ValidateBinarySearchTree.h"
#include <stack>

using namespace lcpp;

static bool isValidBST(TreeNode *Root, TreeNode *&Pre) {
  if (Root == nullptr)
    return true;
  if (!isValidBST(Root->left, Pre))
    return false;
  if (Pre != nullptr && Root->val <= Pre->val)
    return false;
  return isValidBST(Root->right, Pre = Root);
}

bool Solution98_1::isValidBST(TreeNode *root) {
  TreeNode *Pre = nullptr;
  return ::isValidBST(root, Pre);
}

bool Solution98_2::isValidBST(TreeNode *root) {
  TreeNode *Node = root, *Pre = nullptr;
  std::stack<TreeNode *> Stack;
  while (Node != nullptr || !Stack.empty()) {
    if (Node != nullptr) {
      Stack.push(Node);
      Node = Node->left;
    } else {
      Node = Stack.top();
      Stack.pop();
      if (Pre != nullptr && Pre->val >= Node->val)
        return false;
      Pre = Node;
      Node = Node->right;
    }
  }
  return true;
}
