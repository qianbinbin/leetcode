// The n-queens puzzle is the problem of placing n queens on an n x n chessboard
// such that no two queens attack each other.
//
// Given an integer n, return all distinct solutions to the n-queens puzzle.
//
// Each solution contains a distinct board configuration of the n-queens'
// placement, where 'Q' and '.' both indicate a queen and an empty space,
// respectively.
//
//
//
// Example 1:
//
// https://assets.leetcode.com/uploads/2020/11/13/queens.jpg
// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as
// shown above
//
// Example 2:
//
// Input: n = 1
// Output: [["Q"]]
//
//
// Constraints:
//
// 1 <= n <= 9

#ifndef LEETCODECPP_NQUEENS_H
#define LEETCODECPP_NQUEENS_H

#include <string>
#include <vector>

namespace lcpp {

class Solution51_1 {
public:
  std::vector<std::vector<std::string>> solveNQueens(int n);
};

} // namespace lcpp

#endif // LEETCODECPP_NQUEENS_H
