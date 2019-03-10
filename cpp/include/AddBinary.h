// Given two binary strings, return their sum (also a binary string).
//
// The input strings are both non-empty and contains only characters 1 or 0.
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

#ifndef LEETCODECPP_ADDBINARY_H
#define LEETCODECPP_ADDBINARY_H

#include <string>

namespace lcpp {

class Solution67_1 {
public:
  std::string addBinary(std::string a, std::string b);
};

}

#endif //LEETCODECPP_ADDBINARY_H
