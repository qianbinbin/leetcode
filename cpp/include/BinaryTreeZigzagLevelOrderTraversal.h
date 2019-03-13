// Given a binary tree, return the zigzag level order traversal of its nodes'
// values. (ie, from left to right, then right to left for the next level and
// alternate between).
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
// return its zigzag level order traversal as:
//
// [
//   [3],
//   [20,9],
//   [15,7]
// ]

#ifndef LEETCODECPP_BINARYTREEZIGZAGLEVELORDERTRAVERSAL_H
#define LEETCODECPP_BINARYTREEZIGZAGLEVELORDERTRAVERSAL_H

#include "TreeNode.h"
#include <vector>

namespace lcpp {

class Solution103_1 {
public:
  std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root);
};

}

#endif //LEETCODECPP_BINARYTREEZIGZAGLEVELORDERTRAVERSAL_H
