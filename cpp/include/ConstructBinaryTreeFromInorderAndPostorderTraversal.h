// Given inorder and postorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
//
// For example, given
//
// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]
//
// Return the following binary tree:
//
//     3
//    / \
//   9  20
//     /  \
//    15   7

#ifndef LEETCODECPP_CONSTRUCTBINARYTREEFROMINORDERANDPOSTORDERTRAVERSAL_H
#define LEETCODECPP_CONSTRUCTBINARYTREEFROMINORDERANDPOSTORDERTRAVERSAL_H

#include "TreeNode.h"
#include <vector>

namespace lcpp {

class Solution106_1 {
public:
  TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder);
};

}

#endif //LEETCODECPP_CONSTRUCTBINARYTREEFROMINORDERANDPOSTORDERTRAVERSAL_H
