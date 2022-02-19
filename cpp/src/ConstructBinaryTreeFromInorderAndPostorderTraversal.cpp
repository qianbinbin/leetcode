#include "ConstructBinaryTreeFromInorderAndPostorderTraversal.h"
#include <algorithm>

using namespace lcpp;

typedef std::vector<int>::iterator It;

static TreeNode *buildTree(It InBegin, It InEnd, It PostBegin, It PostEnd) {
  if (PostBegin == PostEnd)
    return nullptr;
  auto InRoot = find(InBegin, InEnd, *(PostEnd - 1));
  auto Left = InRoot - InBegin;
  return new TreeNode(
      *(PostEnd - 1), buildTree(InBegin, InRoot, PostBegin, PostBegin + Left),
      buildTree(InRoot + 1, InEnd, PostBegin + Left, PostEnd - 1));
}

TreeNode *Solution106_1::buildTree(std::vector<int> &inorder,
                                   std::vector<int> &postorder) {
  return ::buildTree(inorder.begin(), inorder.end(), postorder.begin(),
                     postorder.end());
}
