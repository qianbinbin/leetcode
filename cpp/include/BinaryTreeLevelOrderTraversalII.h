// Given the root of a binary tree, return the bottom-up level order traversal
// of its nodes' values. (i.e., from left to right, level by level from leaf to
// root).
//
//
//
// Example 1:
// https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg
//
// Input: root = [3,9,20,null,null,15,7]
// Output: [[15,7],[9,20],[3]]
//
// Example 2:
//
// Input: root = [1]
// Output: [[1]]
// Example 3:
//
// Input: root = []
// Output: []
//
//
// Constraints:
//
// The number of nodes in the tree is in the range [0, 2000].
// -1000 <= Node.val <= 1000

#ifndef LEETCODECPP_BINARYTREELEVELORDERTRAVERSALII_H
#define LEETCODECPP_BINARYTREELEVELORDERTRAVERSALII_H

#include "TreeNode.h"
#include <vector>

namespace lcpp {

class Solution107_1 {
public:
  std::vector<std::vector<int>> levelOrderBottom(TreeNode *root);
};

class Solution107_2 {
public:
  std::vector<std::vector<int>> levelOrderBottom(TreeNode *root);
};

} // namespace lcpp

#endif // LEETCODECPP_BINARYTREELEVELORDERTRAVERSALII_H
