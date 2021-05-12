// Given two non-negative integers num1 and num2 represented as strings, return
// the product of num1 and num2, also represented as a string.
//
// Note: You must not use any built-in BigInteger library or convert the inputs
// to integer directly.
//
//
//
// Example 1:
//
// Input: num1 = "2", num2 = "3"
// Output: "6"
//
// Example 2:
//
// Input: num1 = "123", num2 = "456"
// Output: "56088"
//
//
// Constraints:
//
// 1 <= num1.length, num2.length <= 200
// num1 and num2 consist of digits only.
// Both num1 and num2 do not contain any leading zero, except the number 0
// itself.

#ifndef LEETCODECPP_MULTIPLYSTRINGS_H
#define LEETCODECPP_MULTIPLYSTRINGS_H

#include <string>

namespace lcpp {

class Solution43_1 {
public:
  std::string multiply(std::string num1, std::string num2);
};

} // namespace lcpp

#endif // LEETCODECPP_MULTIPLYSTRINGS_H
