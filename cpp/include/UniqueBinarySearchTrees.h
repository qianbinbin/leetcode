// Given n, how many structurally unique BST's (binary search trees) that store
// values 1 ... n?
//
// Example:
//
// Input: 3
// Output: 5
// Explanation:
// Given n = 3, there are a total of 5 unique BST's:
//
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

#ifndef LEETCODECPP_UNIQUEBINARYSEARCHTREES_H
#define LEETCODECPP_UNIQUEBINARYSEARCHTREES_H

#include "TreeNode.h"

namespace lcpp {

class Solution96_1 {
public:
  int numTrees(int n);
};

class Solution96_2 {
public:
  int numTrees(int n);
};

}

#endif //LEETCODECPP_UNIQUEBINARYSEARCHTREES_H
