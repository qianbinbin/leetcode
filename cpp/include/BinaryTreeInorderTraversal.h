// Given a binary tree, return the inorder traversal of its nodes' values.
//
// Example:
//
// Input: [1,null,2,3]
//    1
//    \
//     2
//    /
//    3
//
// Output: [1,3,2]
//
// Follow up: Recursive solution is trivial, could you do it iteratively?

#ifndef LEETCODECPP_BINARYTREEINORDERTRAVERSAL_H
#define LEETCODECPP_BINARYTREEINORDERTRAVERSAL_H

#include "TreeNode.h"
#include <vector>

namespace lcpp {

class Solution94_1 {
public:
  std::vector<int> inorderTraversal(TreeNode *root);
};

class Solution94_2 {
public:
  std::vector<int> inorderTraversal(TreeNode *root);
};

}

#endif //LEETCODECPP_BINARYTREEINORDERTRAVERSAL_H
