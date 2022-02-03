#include "RecoverBinarySearchTree.h"
#include <vector>

using namespace lcpp;

static void inOrder(TreeNode *Root, std::vector<TreeNode *> &Result) {
  if (Root == nullptr)
    return;
  inOrder(Root->left, Result);
  Result.push_back(Root);
  inOrder(Root->right, Result);
}

void Solution99_1::recoverTree(TreeNode *root) {
  std::vector<TreeNode *> Result;
  inOrder(root, Result);
  auto I = Result.begin(), J = Result.end() - 1;
  while (I != J && (*I)->val < (*(I + 1))->val)
    ++I;
  while (J != I && (*J)->val > (*(J - 1))->val)
    --J;
  std::swap((*I)->val, (*J)->val);
}

static void inOrder(TreeNode *Root, TreeNode *&Pre, TreeNode *&P1,
                    TreeNode *&P2) {
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

void Solution99_2::recoverTree(TreeNode *root) {
  TreeNode *Pre = nullptr, *P1 = nullptr, *P2 = nullptr;
  inOrder(root, Pre, P1, P2);
  if (P1 != nullptr && P2 != nullptr)
    std::swap(P1->val, P2->val);
}
