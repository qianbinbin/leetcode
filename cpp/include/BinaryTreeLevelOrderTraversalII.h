// Given a binary tree, return the bottom-up level order traversal of its nodes'
// values. (ie, from left to right, level by level from leaf to root).
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
// return its bottom-up level order traversal as:
//
// [
//   [15,7],
//   [9,20],
//   [3]
// ]

#ifndef LEETCODECPP_BINARYTREELEVELORDERTRAVERSALII_H
#define LEETCODECPP_BINARYTREELEVELORDERTRAVERSALII_H

#include "TreeNode.h"
#include <vector>

namespace lcpp {

class Solution107_1 {
public:
  std::vector<std::vector<int>> levelOrderBottom(TreeNode *root);
};

}

#endif //LEETCODECPP_BINARYTREELEVELORDERTRAVERSALII_H
