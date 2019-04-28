#include "LowestCommonAncestorOfABinaryTree.h"
#include <vector>

using namespace lcpp;

/// Root cannot be nullptr.
static bool findPath(TreeNode *Root, TreeNode *Node,
                     std::vector<TreeNode *> &Path) {
  Path.push_back(Root);
  if (Root == Node)
    return true;
  if (Root->left != nullptr && findPath(Root->left, Node, Path))
    return true;
  if (Root->right != nullptr && findPath(Root->right, Node, Path))
    return true;
  Path.pop_back();
  return false;
}

TreeNode *Solution236_1::lowestCommonAncestor(TreeNode *root, TreeNode *p,
                                              TreeNode *q) {
  if (root == nullptr)
    return nullptr;
  std::vector<TreeNode *> Path1, Path2;
  findPath(root, p, Path1);
  findPath(root, q, Path2);
  TreeNode *Result = nullptr;
  for (std::vector<TreeNode *>::size_type I = 0, E = std::min(Path1.size(),
                                                              Path2.size());
       I != E && Path1[I] == Path2[I]; ++I)
    Result = Path1[I];
  return Result;
}
