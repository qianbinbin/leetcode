#include "RecoverBinarySearchTree.h"
#include <algorithm>

using namespace lcpp;

static void inOrder(TreeNode *Root, TreeNode *&Pre,
                    TreeNode *&P1, TreeNode *&P2) {
  if (Root == nullptr)
    return;
  inOrder(Root->left, Pre, P1, P2);
  if (Pre != nullptr && Pre->val > Root->val) {
    if (P1 == nullptr)
      P1 = Pre;
    P2 = Root;
  }
  inOrder(Root->right, Pre = Root, P1, P2);
}

void Solution99_1::recoverTree(TreeNode *root) {
  TreeNode *Pre = nullptr, *P1 = nullptr, *P2 = nullptr;
  inOrder(root, Pre, P1, P2);
  if (P1 != nullptr && P2 != nullptr)
    std::swap(P1->val, P2->val);
}
