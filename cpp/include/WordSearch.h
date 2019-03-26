// Given a 2D board and a word, find if the word exists in the grid.
//
// The word can be constructed from letters of sequentially adjacent cell, where
// "adjacent" cells are those horizontally or vertically neighboring. The same
// letter cell may not be used more than once.
//
// Example:
//
// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]
//
// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.

#ifndef LEETCODECPP_WORDSEARCH_H
#define LEETCODECPP_WORDSEARCH_H

#include <string>
#include <vector>

namespace lcpp {

class Solution79_1 {
public:
  bool exist(std::vector<std::vector<char>> &board, std::string word);
};

}

#endif //LEETCODECPP_WORDSEARCH_H
