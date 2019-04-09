// A message containing letters from A-Z is being encoded to numbers using the
// following mapping:
//
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
//
// Given a non-empty string containing only digits, determine the total number
// of ways to decode it.
//
// Example 1:
//
// Input: "12"
// Output: 2
// Explanation: It could be decoded as "AB" (1 2) or "L" (12).
//
// Example 2:
//
// Input: "226"
// Output: 3
// Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
// 6).

#ifndef LEETCODECPP_DECODEWAYS_H
#define LEETCODECPP_DECODEWAYS_H

#include <string>

namespace lcpp {

class Solution91_1 {
public:
  int numDecodings(std::string s);
};

} // namespace lcpp

#endif // LEETCODECPP_DECODEWAYS_H
