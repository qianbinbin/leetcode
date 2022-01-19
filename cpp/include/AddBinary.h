// Given two binary strings a and b, return their sum as a binary string.
//
//
//
// Example 1:
//
// Input: a = "11", b = "1"
// Output: "100"
//
// Example 2:
//
// Input: a = "1010", b = "1011"
// Output: "10101"
//
//
// Constraints:
//
// 1 <= a.length, b.length <= 104
// a and b consist only of '0' or '1' characters.
// Each string does not contain leading zeros except for the zero itself.

#ifndef LEETCODECPP_ADDBINARY_H
#define LEETCODECPP_ADDBINARY_H

#include <string>

namespace lcpp {

class Solution67_1 {
public:
  std::string addBinary(std::string a, std::string b);
};

} // namespace lcpp

#endif // LEETCODECPP_ADDBINARY_H
