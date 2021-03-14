#include "LetterCombinationsOfAPhoneNumber.h"

using namespace lcpp;

static void combination(std::string::iterator I, std::string::iterator E,
                        std::array<std::string, 8> const &Keyboard,
                        std::string &Path, std::vector<std::string> &Result) {
  if (I == E) {
    Result.push_back(Path);
    return;
  }
  for (auto const &Ch : Keyboard[*I - '2']) {
    Path.push_back(Ch);
    combination(I + 1, E, Keyboard, Path, Result);
    Path.pop_back();
  }
}

std::vector<std::string> Solution17_1::letterCombinations(std::string digits) {
  std::vector<std::string> Result;
  if (digits.empty())
    return Result;
  std::array<std::string, 8> const Keyboard = {"abc", "def",  "ghi", "jkl",
                                               "mno", "pqrs", "tuv", "wxyz"};
  std::string Path;
  combination(digits.begin(), digits.end(), Keyboard, Path, Result);
  return Result;
}
