// Given a string s consists of upper/lower-case alphabets and empty space
// characters ' ', return the length of last word in the string.
//
// If the last word does not exist, return 0.
//
// Note: A word is defined as a character sequence consists of non-space
// characters only.
//
// Example:
//
// Input: "Hello World"
// Output: 5

#ifndef LEETCODECPP_LENGTHOFLASTWORD_H
#define LEETCODECPP_LENGTHOFLASTWORD_H

#include <string>

namespace lcpp {

class Solution58_1 {
public:
  int lengthOfLastWord(std::string s);
};

}

#endif //LEETCODECPP_LENGTHOFLASTWORD_H
