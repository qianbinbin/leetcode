// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
// Example 1:
//
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true
//
// Example 2:
//
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// Output: false

#ifndef LEETCODECPP_INTERLEAVINGSTRING_H
#define LEETCODECPP_INTERLEAVINGSTRING_H

#include <string>

namespace lcpp {

class Solution97_1 {
public:
  bool isInterleave(std::string s1, std::string s2, std::string s3);
};

} // namespace lcpp

#endif // LEETCODECPP_INTERLEAVINGSTRING_H
