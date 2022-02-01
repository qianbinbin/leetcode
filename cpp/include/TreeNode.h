#ifndef LEETCODECPP_TREENODE_H
#define LEETCODECPP_TREENODE_H

#include <initializer_list>
#include <limits>

namespace lcpp {

const int NTNode = std::numeric_limits<int>::min();

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

TreeNode *newTree(std::initializer_list<int> List);

void deleteTree(struct TreeNode *Root);

inline bool treeEqual(const TreeNode *Root1, const TreeNode *Root2) {
  if (Root1 == Root2)
    return true;
  if (Root1 == nullptr || Root2 == nullptr)
    return false;
  if (Root1->val != Root2->val)
    return false;
  return treeEqual(Root1->left, Root2->left) &&
         treeEqual(Root1->right, Root2->right);
}

inline bool operator==(const TreeNode &Root1, const TreeNode &Root2) {
  return treeEqual(&Root1, &Root2);
}

} // namespace lcpp

#endif // LEETCODECPP_TREENODE_H
