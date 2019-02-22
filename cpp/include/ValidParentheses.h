// Given a string containing just the characters '(', ')', '{', '}',
// '[' and ']', determine if the input string is valid.
//
// An input string is valid if:
//
// 1. Open brackets must be closed by the same type of brackets.
// 2. Open brackets must be closed in the correct order.
//
// Note that an empty string is also considered valid.
//
// Example 1:
//
// Input: "()"
// Output: true
//
// Example 2:
//
// Input: "()[]{}"
// Output: true
//
// Example 3:
//
// Input: "(]"
// Output: false
//
// Example 4:
//
// Input: "([)]"
// Output: false
//
// Example 5:
//
// Input: "{[]}"
// Output: true

#ifndef LEETCODECPP_VALIDPARENTHESES_H
#define LEETCODECPP_VALIDPARENTHESES_H

#include <string>

namespace lcpp {

class Solution20_1 {
public:
  bool isValid(std::string s);
};

}

#endif //LEETCODECPP_VALIDPARENTHESES_H
