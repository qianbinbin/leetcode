#include "ConstructBinaryTreeFromPreorderAndInorderTraversal.h"
#include <algorithm>
#include <cassert>

using namespace lcpp;

typedef std::vector<int>::iterator It;

static TreeNode *buildTree(It PreBegin, It PreEnd, It InBegin, It InEnd) {
  if (PreBegin == PreEnd)
    return nullptr;
  auto Root = new TreeNode(*PreBegin);
  auto InRoot = find(InBegin, InEnd, *PreBegin);
  assert(InRoot != InEnd);
  auto Left = InRoot - InBegin;
  Root->left = buildTree(PreBegin + 1, PreBegin + 1 + Left, InBegin, InRoot);
  Root->right = buildTree(PreBegin + 1 + Left, PreEnd, InRoot + 1, InEnd);
  return Root;
}

TreeNode *Solution105_1::buildTree(std::vector<int> &preorder,
                                   std::vector<int> &inorder) {
  assert(preorder.size() == inorder.size());
  return ::buildTree(preorder.begin(), preorder.end(),
                     inorder.begin(), inorder.end());
}
