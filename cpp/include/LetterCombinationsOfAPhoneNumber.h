// Given a string containing digits from 2-9 inclusive, return all possible
// letter combinations that the number could represent.
//
// A mapping of digit to letters (just like on the telephone buttons) is given
// below. Note that 1 does not map to any letters.
//
// http://upload.wikimedia.org/wikipedia/commons/thumb/7/73/
// Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png
//
// Example:
//
// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//
// Note:
//
// Although the above answer is in lexicographical order, your answer could be
// in any order you want.

#ifndef LEETCODECPP_LETTERCOMBINATIONSOFAPHONENUMBER_H
#define LEETCODECPP_LETTERCOMBINATIONSOFAPHONENUMBER_H

#include <array>
#include <string>
#include <vector>

namespace lcpp {

class Solution17_1 {
  const std::array<std::string, 8> Keyboard{
      "abc",
      "def",
      "ghi",
      "jkl",
      "mno",
      "pqrs",
      "tuv",
      "wxyz"
  };

  void combination(std::string::iterator I, std::string::iterator E,
                   std::string &Path, std::vector<std::string> &Result);

public:
  std::vector<std::string> letterCombinations(std::string digits);
};

}

#endif //LEETCODECPP_LETTERCOMBINATIONSOFAPHONENUMBER_H
