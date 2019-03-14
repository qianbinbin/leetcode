#include "ConstructBinaryTreeFromInorderAndPostorderTraversal.h"
#include <algorithm>
#include <cassert>

using namespace lcpp;

typedef std::vector<int>::iterator It;

static TreeNode *buildTree(It InBegin, It InEnd, It PostBegin, It PostEnd) {
  if (PostBegin == PostEnd)
    return nullptr;
  auto Root = new TreeNode(*(PostEnd - 1));
  auto InRoot = find(InBegin, InEnd, *(PostEnd - 1));
  assert(InRoot != InEnd);
  auto Left = InRoot - InBegin;
  Root->left = buildTree(InBegin, InRoot, PostBegin, PostBegin + Left);
  Root->right = buildTree(InRoot + 1, InEnd, PostBegin + Left, PostEnd - 1);
  return Root;
}

TreeNode *Solution106_1::buildTree(std::vector<int> &inorder,
                                   std::vector<int> &postorder) {
  assert(inorder.size() == postorder.size());
  return ::buildTree(inorder.begin(), inorder.end(),
                     postorder.begin(), postorder.end());
}
