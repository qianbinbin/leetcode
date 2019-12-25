#include "InvertBinaryTree.h"
#include <algorithm>

using namespace lcpp;

static void invertTree(TreeNode *Root) {
  if (Root == nullptr)
    return;
  std::swap(Root->left, Root->right);
  invertTree(Root->left);
  invertTree(Root->right);
}

TreeNode *Solution226_1::invertTree(TreeNode *root) {
  ::invertTree(root);
  return root;
}
