#include "UniqueBinarySearchTreesII.h"

using namespace lcpp;

static TreeNode *copyTree(TreeNode *Root) {
  if (Root == nullptr)
    return nullptr;
  auto Copy = new TreeNode(Root->val);
  Copy->left = copyTree(Root->left);
  Copy->right = copyTree(Root->right);
  return Copy;
}

static void delTree(TreeNode *Root) {
  if (Root == nullptr)
    return;
  delTree(Root->left);
  delTree(Root->right);
  delete Root;
}

static void genTrees(int Begin, int End, std::vector<TreeNode *> &Trees) {
  if (Begin == End) {
    Trees.push_back(nullptr);
    return;
  }
  std::vector<TreeNode *> LeftTrees, RightTrees;
  for (int I = Begin; I != End; ++I) {
    genTrees(Begin, I, LeftTrees);
    genTrees(I + 1, End, RightTrees);
    for (const auto &L : LeftTrees) {
      for (const auto &R : RightTrees) {
        auto Root = new TreeNode(I);
        Root->left = copyTree(L);
        Root->right = copyTree(R);
        Trees.push_back(Root);
      }
    }
    for (const auto &L : LeftTrees)
      delTree(L);
    LeftTrees.clear();
    for (const auto &R : RightTrees)
      delTree(R);
    RightTrees.clear();
  }
}

std::vector<TreeNode *> Solution95_1::generateTrees(int n) {
  // assert(n > 0);
  std::vector<TreeNode *> Trees;
  if (n <= 0)
    return Trees;
  genTrees(1, n + 1, Trees);
  return Trees;
}
