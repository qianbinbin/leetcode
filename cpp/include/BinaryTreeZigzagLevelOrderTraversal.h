// Given the root of a binary tree, return the zigzag level order traversal of
// its nodes' values. (i.e., from left to right, then right to left for the next
// level and alternate between).
//
//
//
// Example 1:
// https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg
//
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]
//
// Example 2:
//
// Input: root = [1]
// Output: [[1]]
//
// Example 3:
//
// Input: root = []
// Output: []
//
//
// Constraints:
//
// The number of nodes in the tree is in the range [0, 2000].
// -100 <= Node.val <= 100

#ifndef LEETCODECPP_BINARYTREEZIGZAGLEVELORDERTRAVERSAL_H
#define LEETCODECPP_BINARYTREEZIGZAGLEVELORDERTRAVERSAL_H

#include "TreeNode.h"
#include <vector>

namespace lcpp {

class Solution103_1 {
public:
  std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root);
};

class Solution103_2 {
public:
  std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root);
};

} // namespace lcpp

#endif // LEETCODECPP_BINARYTREEZIGZAGLEVELORDERTRAVERSAL_H
