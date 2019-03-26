// The n-queens puzzle is the problem of placing n queens on an n×n chessboard
// such that no two queens attack each other.
//
// https://assets.leetcode.com/uploads/2018/10/12/8-queens.png
//
// Given an integer n, return all distinct solutions to the n-queens puzzle.
//
// Each solution contains a distinct board configuration of the n-queens'
// placement, where 'Q' and '.' both indicate a queen and an empty space
// respectively.
//
// Example:
//
// Input: 4
// Output: [
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
// Explanation: There exist two distinct solutions to the 4-queens puzzle as
// shown above.

#ifndef LEETCODECPP_NQUEENS_H
#define LEETCODECPP_NQUEENS_H

#include <string>
#include <vector>

namespace lcpp {

class Solution51_1 {
public:
  std::vector<std::vector<std::string>> solveNQueens(int n);
};

}

#endif //LEETCODECPP_NQUEENS_H
