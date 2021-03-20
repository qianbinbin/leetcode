#include "SubstringWithConcatenationOfAllWords.h"
#include <unordered_map>

using namespace lcpp;

std::vector<int> Solution30_1::findSubstring(std::string s,
                                             std::vector<std::string> &words) {
  auto const &Size = words.size();
  auto const &Width = words[0].size();
  auto const Length = Size * Width;
  std::vector<int> Result;
  if (Length > s.size())
    return Result;

  std::unordered_map<std::string, int> Expected, Actual;
  for (auto &Word : words)
    ++Expected[Word];
  std::unordered_map<std::string, int>::iterator EI, EE = Expected.end();
  std::string::size_type I = 0, IE = s.size() - Width + 1;
  std::vector<std::string>::size_type Count = 0;
  while (I < IE) {
    auto Word = s.substr(I, Width);
    if ((EI = Expected.find(Word)) != EE && EI->second >= ++Actual[Word]) {
      if (++Count == Size) {
        I -= (Size - 1) * Width;
        Result.push_back(I);
        Count = 0;
        Actual.clear();
        ++I;
      } else {
        I += Width;
      }
    } else {
      Actual.clear();
      I -= Count * Width - 1;
      Count = 0;
    }
  }
  return Result;
}
