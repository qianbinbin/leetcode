// Given a binary tree and a sum, find all root-to-leaf paths where each path's
// sum equals the given sum.
//
// Note: A leaf is a node with no children.
//
// Example:
//
// Given the below binary tree and sum = 22,
//
//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \    / \
// 7    2  5   1
//
// Return:
//
// [
//   [5,4,11,2],
//   [5,8,4,5]
// ]

#ifndef LEETCODECPP_PATHSUMII_H
#define LEETCODECPP_PATHSUMII_H

#include "TreeNode.h"
#include <vector>

namespace lcpp {

class Solution113_1 {
public:
  std::vector<std::vector<int>> pathSum(TreeNode *root, int sum);
};

}

#endif //LEETCODECPP_PATHSUMII_H
