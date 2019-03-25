#include "LetterCombinationsOfAPhoneNumber.h"

using namespace lcpp;

void Solution17_1::combination(std::string::iterator I,
                               std::string::iterator E,
                               std::string &Path,
                               std::vector<std::string> &Result) {
  if (I == E) {
    Result.push_back(Path);
    return;
  }
  for (const auto &Ch : Keyboard[*I - '2']) {
    Path.push_back(Ch);
    combination(I + 1, E, Path, Result);
    Path.pop_back();
  }
}

std::vector<std::string> Solution17_1::letterCombinations(std::string digits) {
  std::vector<std::string> Result;
  if (digits.empty())
    return Result;
  std::string Path;
  combination(digits.begin(), digits.end(), Path, Result);
  return Result;
}
