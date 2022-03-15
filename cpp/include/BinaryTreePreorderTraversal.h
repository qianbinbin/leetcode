// Given the root of a binary tree, return the preorder traversal of its nodes'
// values.
//
//
//
// Example 1:
// https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg
//
// Input: root = [1,null,2,3]
// Output: [1,2,3]
//
// Example 2:
//
// Input: root = []
// Output: []
//
// Example 3:
//
// Input: root = [1]
// Output: [1]
//
//
// Constraints:
//
// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100
//
//
// Follow up: Recursive solution is trivial, could you do it iteratively?

#ifndef LEETCODECPP_BINARYTREEPREORDERTRAVERSAL_H
#define LEETCODECPP_BINARYTREEPREORDERTRAVERSAL_H

#include "TreeNode.h"
#include <vector>

namespace lcpp {

class Solution144_1 {
public:
  std::vector<int> preorderTraversal(TreeNode *root);
};

class Solution144_2 {
public:
  std::vector<int> preorderTraversal(TreeNode *root);
};

} // namespace lcpp

#endif // LEETCODECPP_BINARYTREEPREORDERTRAVERSAL_H
