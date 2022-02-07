// Given the root of a binary tree, return its maximum depth.
//
// A binary tree's maximum depth is the number of nodes along the longest path
// from the root node down to the farthest leaf node.
//
//
//
// Example 1:
// https://assets.leetcode.com/uploads/2020/11/26/tmp-tree.jpg
//
// Input: root = [3,9,20,null,null,15,7]
// Output: 3
//
// Example 2:
//
// Input: root = [1,null,2]
// Output: 2
//
//
// Constraints:
//
// The number of nodes in the tree is in the range [0, 104].
// -100 <= Node.val <= 100

#ifndef LEETCODECPP_MAXIMUMDEPTHOFBINARYTREE_H
#define LEETCODECPP_MAXIMUMDEPTHOFBINARYTREE_H

#include "TreeNode.h"

namespace lcpp {

class Solution104_1 {
public:
  int maxDepth(TreeNode *root);
};

} // namespace lcpp

#endif // LEETCODECPP_MAXIMUMDEPTHOFBINARYTREE_H
