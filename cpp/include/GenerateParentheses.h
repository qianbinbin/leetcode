// Given n pairs of parentheses, write a function to generate all combinations
// of well-formed parentheses.
//
// For example, given n = 3, a solution set is:
//
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

#ifndef LEETCODECPP_GENERATEPARENTHESES_H
#define LEETCODECPP_GENERATEPARENTHESES_H

#include <string>
#include <vector>

namespace lcpp {

class Solution22_1 {
public:
  std::vector<std::string> generateParenthesis(int n);
};

}

#endif //LEETCODECPP_GENERATEPARENTHESES_H
