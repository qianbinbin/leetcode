// The n-queens puzzle is the problem of placing n queens on an n×n chessboard
// such that no two queens attack each other.
//
// https://assets.leetcode.com/uploads/2018/10/12/8-queens.png
//
// Given an integer n, return the number of distinct solutions to the n-queens
// puzzle.
//
// Example:
//
// Input: 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown
// below.
// [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],
//
//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]

#ifndef LEETCODECPP_NQUEENSII_H
#define LEETCODECPP_NQUEENSII_H

namespace lcpp {

class Solution52_1 {
public:
  int totalNQueens(int n);
};

}

#endif //LEETCODECPP_NQUEENSII_H
