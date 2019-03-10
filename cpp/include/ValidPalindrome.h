// Given a string, determine if it is a palindrome, considering only
// alphanumeric characters and ignoring cases.
//
// Note: For the purpose of this problem, we define empty string as valid
// palindrome.
//
// Example 1:
//
// Input: "A man, a plan, a canal: Panama"
// Output: true
//
// Example 2:
//
// Input: "race a car"
// Output: false

#ifndef LEETCODECPP_VALIDPALINDROME_H
#define LEETCODECPP_VALIDPALINDROME_H

#include <string>

namespace lcpp {

class Solution125_1 {
public:
  bool isPalindrome(std::string s);
};

}

#endif //LEETCODECPP_VALIDPALINDROME_H
