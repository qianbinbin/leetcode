#include "SymmetricTree.h"

using namespace lcpp;

static bool isSymmetric(TreeNode *Root1, TreeNode *Root2) {
  if (Root1 == nullptr && Root2 == nullptr)
    return true;
  if (Root1 == nullptr || Root2 == nullptr)
    return false;
  if (Root1->val != Root2->val)
    return false;
  return isSymmetric(Root1->left, Root2->right)
      && isSymmetric(Root1->right, Root2->left);
}

bool Solution101_1::isSymmetric(TreeNode *root) {
  if (root == nullptr)
    return true;
  return ::isSymmetric(root->left, root->right);
}
