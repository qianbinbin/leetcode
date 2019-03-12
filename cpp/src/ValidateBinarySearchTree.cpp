#include "ValidateBinarySearchTree.h"

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
