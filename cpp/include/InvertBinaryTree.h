// Invert a binary tree.
//
// Example:
//
// Input:
//
//      4
//    /   \
//   2     7
//  / \   / \
// 1   3 6   9
//
// Output:
//
//      4
//    /   \
//   7     2
//  / \   / \
// 9   6 3   1
//
// Trivia:
// This problem was inspired by this original tweet by Max Howell:
//
// Google: 90% of our engineers use the software you wrote (Homebrew), but you
// can’t invert a binary tree on a whiteboard so f*** off.

#ifndef LEETCODECPP_INVERTBINARYTREE_H
#define LEETCODECPP_INVERTBINARYTREE_H

#include "TreeNode.h"

namespace lcpp {

class Solution226_1 {
public:
  TreeNode *invertTree(TreeNode *root);
};

} // namespace lcpp

#endif // LEETCODECPP_INVERTBINARYTREE_H
