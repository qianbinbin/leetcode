#include "LowestCommonAncestorOfABinaryTree.h"
#include <unordered_map>
#include <unordered_set>
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

/// Return lowest common ancestor if the tree contains both P and Q,
/// or one of them if the tree only contains that one,
/// or nullptr if neither is in the tree.
static TreeNode *lowestAncestor(TreeNode *Root, TreeNode *P, TreeNode *Q) {
  if (Root == nullptr || Root == P || Root == Q)
    return Root;
  auto L = lowestAncestor(Root->left, P, Q),
       R = lowestAncestor(Root->right, P, Q);
  if (L != nullptr && R != nullptr)
    return Root;
  return L != nullptr ? L : R;
}

TreeNode *Solution236_2::lowestCommonAncestor(TreeNode *root, TreeNode *p,
                                              TreeNode *q) {
  return lowestAncestor(root, p, q);
}

/// Root cannot be nullptr.
static void findParents(TreeNode *Root,
                        std::unordered_map<TreeNode *, TreeNode *> &Parents) {
  if (Root->left != nullptr) {
    Parents[Root->left] = Root;
    findParents(Root->left, Parents);
  }
  if (Root->right != nullptr) {
    Parents[Root->right] = Root;
    findParents(Root->right, Parents);
  }
}

TreeNode *Solution236_3::lowestCommonAncestor(TreeNode *root, TreeNode *p,
                                              TreeNode *q) {
  if (root == nullptr)
    return nullptr;
  std::unordered_map<TreeNode *, TreeNode *> Parents{{root, nullptr}};
  findParents(root, Parents);
  const auto &PE = Parents.end();
  if (Parents.find(p) == PE || Parents.find(q) == PE)
    return nullptr;
  std::unordered_set<TreeNode *> Ancestors;
  while (p != nullptr) {
    Ancestors.insert(p);
    p = Parents[p];
  }
  const auto &AE = Ancestors.end();
  while (Ancestors.find(q) == AE)
    q = Parents[q];
  return q;
}
