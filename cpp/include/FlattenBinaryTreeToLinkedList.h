// Given a binary tree, flatten it to a linked list in-place.
//
// For example, given the following tree:
//
//     1
//    / \
//   2   5
//  / \   \
// 3   4   6
//
// The flattened tree should look like:
//
// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6

#ifndef LEETCODECPP_FLATTENBINARYTREETOLINKEDLIST_H
#define LEETCODECPP_FLATTENBINARYTREETOLINKEDLIST_H

#include "TreeNode.h"

namespace lcpp {

class Solution114_1 {
public:
  void flatten(TreeNode *root);
};

}

#endif //LEETCODECPP_FLATTENBINARYTREETOLINKEDLIST_H
