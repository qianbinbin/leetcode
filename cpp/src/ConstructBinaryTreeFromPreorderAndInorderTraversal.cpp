#include "ConstructBinaryTreeFromPreorderAndInorderTraversal.h"
#include <algorithm>

using namespace lcpp;

typedef std::vector<int>::iterator It;

static TreeNode *buildTree(It PreBegin, It PreEnd, It InBegin, It InEnd) {
  if (PreBegin == PreEnd)
    return nullptr;
  auto InRoot = find(InBegin, InEnd, *PreBegin);
  auto Left = InRoot - InBegin;
  return new TreeNode(
      *PreBegin, buildTree(PreBegin + 1, PreBegin + 1 + Left, InBegin, InRoot),
      buildTree(PreBegin + 1 + Left, PreEnd, InRoot + 1, InEnd));
}

TreeNode *Solution105_1::buildTree(std::vector<int> &preorder,
                                   std::vector<int> &inorder) {
  return ::buildTree(preorder.begin(), preorder.end(), inorder.begin(),
                     inorder.end());
}
