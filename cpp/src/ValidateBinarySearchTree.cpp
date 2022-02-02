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

static bool isValidBST(TreeNode *root, int64_t min, int64_t max) {
  if (root == nullptr)
    return true;
  if (root->val <= min || root->val >= max)
    return false;
  return isValidBST(root->left, min, root->val) &&
         isValidBST(root->right, root->val, max);
}

bool Solution98_3::isValidBST(TreeNode *root) {
  return ::isValidBST(root, INT64_MIN, INT64_MAX);
}