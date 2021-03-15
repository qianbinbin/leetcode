// Given a string s containing just the characters '(', ')', '{', '}', '[' and
// ']', determine if the input string is valid.
//
// An input string is valid if:
//
// 1. Open brackets must be closed by the same type of brackets.
// 2. Open brackets must be closed in the correct order.
//
//
// Example 1:
//
// Input: s = "()"
// Output: true
//
// Example 2:
//
// Input: s = "()[]{}"
// Output: true
//
// Example 3:
//
// Input: s = "(]"
// Output: false
//
// Example 4:
//
// Input: s = "([)]"
// Output: false
//
// Example 5:
//
// Input: s = "{[]}"
// Output: true
//
//
// Constraints:
//
// 1 <= s.length <= 10^4
// s consists of parentheses only '()[]{}'.

#ifndef LEETCODECPP_VALIDPARENTHESES_H
#define LEETCODECPP_VALIDPARENTHESES_H

#include <string>

namespace lcpp {

class Solution20_1 {
public:
  bool isValid(std::string s);
};

} // namespace lcpp

#endif // LEETCODECPP_VALIDPARENTHESES_H
