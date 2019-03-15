// Given a non-empty binary tree, find the maximum path sum.
//
// For this problem, a path is defined as any sequence of nodes from some
// starting node to any node in the tree along the parent-child connections. The
// path must contain at least one node and does not need to go through the root.
//
// Example 1:
//
// Input: [1,2,3]
//
//        1
//       / \
//      2   3
//
// Output: 6
//
// Example 2:
//
// Input: [-10,9,20,null,null,15,7]
//
//    -10
//    / \
//   9  20
//     /  \
//    15   7
//
// Output: 42

#ifndef LEETCODECPP_BINARYTREEMAXIMUMPATHSUM_H
#define LEETCODECPP_BINARYTREEMAXIMUMPATHSUM_H

#include "TreeNode.h"

namespace lcpp {

class Solution124_1 {
public:
  int maxPathSum(TreeNode *root);
};

}

#endif //LEETCODECPP_BINARYTREEMAXIMUMPATHSUM_H
