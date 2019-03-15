// Given a binary tree, return the preorder traversal of its nodes' values.
//
// Example:
//
// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3
//
// Output: [1,2,3]
//
// Follow up: Recursive solution is trivial, could you do it iteratively?

#ifndef LEETCODECPP_BINARYTREEPREORDERTRAVERSAL_H
#define LEETCODECPP_BINARYTREEPREORDERTRAVERSAL_H

#include "TreeNode.h"
#include <vector>

namespace lcpp {

class Solution144_1 {
public:
  std::vector<int> preorderTraversal(TreeNode *root);
};

}

#endif //LEETCODECPP_BINARYTREEPREORDERTRAVERSAL_H
