// Given a binary tree, determine if it is a valid binary search tree (BST).
//
// Assume a BST is defined as follows:
//
// The left subtree of a node contains only nodes with keys less than the node's
// key.
// The right subtree of a node contains only nodes with keys greater than the
// node's key.
// Both the left and right subtrees must also be binary search trees.
//
// Example 1:
//
// Input:
//     2
//    / \
//   1   3
// Output: true
//
// Example 2:
//
//     5
//    / \
//   1   4
//      / \
//     3   6
// Output: false
// Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
// is 5 but its right child's value is 4.

#ifndef LEETCODECPP_VALIDATEBINARYSEARCHTREE_H
#define LEETCODECPP_VALIDATEBINARYSEARCHTREE_H

#include "TreeNode.h"

namespace lcpp {

class Solution98_1 {
public:
  bool isValidBST(TreeNode *root);
};

class Solution98_2 {
public:
  bool isValidBST(TreeNode *root);
};

}

#endif //LEETCODECPP_VALIDATEBINARYSEARCHTREE_H
