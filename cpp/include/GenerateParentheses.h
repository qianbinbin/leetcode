// Given n pairs of parentheses, write a function to generate all combinations
// of well-formed parentheses.
//
//
//
// Example 1:
//
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

// Example 2:
//
// Input: n = 1
// Output: ["()"]
//
//
// Constraints:
//
// 1 <= n <= 8

#ifndef LEETCODECPP_GENERATEPARENTHESES_H
#define LEETCODECPP_GENERATEPARENTHESES_H

#include <string>
#include <vector>

namespace lcpp {

class Solution22_1 {
public:
  std::vector<std::string> generateParenthesis(int n);
};

} // namespace lcpp

#endif // LEETCODECPP_GENERATEPARENTHESES_H
