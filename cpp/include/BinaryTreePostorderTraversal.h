// Given the root of a binary tree, return the postorder traversal of its nodes'
// values.
//
//
//
// Example 1:
// https://assets.leetcode.com/uploads/2020/08/28/pre1.jpg
//
// Input: root = [1,null,2,3]
// Output: [3,2,1]
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
// The number of the nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100
//
//
// Follow up: Recursive solution is trivial, could you do it iteratively?

#ifndef LEETCODECPP_BINARYTREEPOSTORDERTRAVERSAL_H
#define LEETCODECPP_BINARYTREEPOSTORDERTRAVERSAL_H

#include "TreeNode.h"
#include <vector>

namespace lcpp {

class Solution145_1 {
public:
  std::vector<int> postorderTraversal(TreeNode *root);
};

class Solution145_2 {
public:
  std::vector<int> postorderTraversal(TreeNode *root);
};

class Solution145_3 {
public:
  std::vector<int> postorderTraversal(TreeNode *root);
};

} // namespace lcpp

#endif // LEETCODECPP_BINARYTREEPOSTORDERTRAVERSAL_H
