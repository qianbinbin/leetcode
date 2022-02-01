#include "UniqueBinarySearchTreesII.h"

using namespace lcpp;

static TreeNode *copyTree(TreeNode *Root) {
  if (Root == nullptr)
    return nullptr;
  return new TreeNode(Root->val, copyTree(Root->left), copyTree(Root->right));
}

static void delTree(TreeNode *Root) {
  if (Root == nullptr)
    return;
  delTree(Root->left);
  delTree(Root->right);
  delete Root;
}

static std::vector<TreeNode *> genTrees(int Begin, int End) {
  std::vector<TreeNode *> Results;
  if (Begin == End) {
    Results.push_back(nullptr);
    return Results;
  }
  for (int I = Begin; I != End; ++I) {
    auto LeftTrees = genTrees(Begin, I);
    auto RightTrees = genTrees(I + 1, End);
    for (const auto &L : LeftTrees) {
      for (const auto &R : RightTrees) {
        Results.push_back(new TreeNode(I, copyTree(L), copyTree(R)));
      }
    }
    for (const auto &L : LeftTrees)
      delTree(L);
    LeftTrees.clear();
    for (const auto &R : RightTrees)
      delTree(R);
    RightTrees.clear();
  }
  return Results;
}

std::vector<TreeNode *> Solution95_1::generateTrees(int n) {
  return genTrees(1, n + 1);
}
