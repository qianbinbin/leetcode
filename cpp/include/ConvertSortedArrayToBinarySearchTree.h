// Given an array where elements are sorted in ascending order, convert it to a
// height balanced BST.
//
// For this problem, a height-balanced binary tree is defined as a binary tree
// in which the depth of the two subtrees of every node never differ by more
// than 1.
//
// Example:
//
// Given the sorted array: [-10,-3,0,5,9],
//
// One possible answer is: [0,-3,9,-10,null,5], which represents the following
// height balanced BST:
//
//       0
//      / \
//    -3   9
//    /   /
//  -10  5

#ifndef LEETCODECPP_CONVERTSORTEDARRAYTOBINARYSEARCHTREE_H
#define LEETCODECPP_CONVERTSORTEDARRAYTOBINARYSEARCHTREE_H

#include "TreeNode.h"
#include <vector>

namespace lcpp {

class Solution108_1 {
public:
  TreeNode *sortedArrayToBST(std::vector<int> &nums);
};

}

#endif //LEETCODECPP_CONVERTSORTEDARRAYTOBINARYSEARCHTREE_H
