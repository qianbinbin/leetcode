#include "SameTree.h"

using namespace lcpp;

bool Solution100_1::isSameTree(TreeNode *p, TreeNode *q) {
  if (p == q)
    return true;
  if (p == nullptr || q == nullptr)
    return false;
  if (p->val != q->val)
    return false;
  return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
