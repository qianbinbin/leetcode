// Given preorder and inorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
//
// For example, given
//
// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
//
// Return the following binary tree:
//
//     3
//    / \
//   9  20
//     /  \
//    15   7

#ifndef LEETCODECPP_CONSTRUCTBINARYTREEFROMPREORDERANDINORDERTRAVERSAL_H
#define LEETCODECPP_CONSTRUCTBINARYTREEFROMPREORDERANDINORDERTRAVERSAL_H

#include "TreeNode.h"
#include <vector>

namespace lcpp {

class Solution105_1 {
public:
  TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder);
};

}

#endif //LEETCODECPP_CONSTRUCTBINARYTREEFROMPREORDERANDINORDERTRAVERSAL_H
