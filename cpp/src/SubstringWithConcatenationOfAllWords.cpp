#include "SubstringWithConcatenationOfAllWords.h"
#include <unordered_map>

using namespace lcpp;

std::vector<int> Solution30_1::findSubstring(std::string s,
                                             std::vector<std::string> &words) {
  std::vector<int> Result;
  const auto &Size = words.size();
  if (Size == 0)
    return Result;
  const auto &Width = words[0].size();
  if (Width == 0)
    return Result;
  const auto Length = Size * Width;
  if (s.size() < Length)
    return Result;

  std::unordered_map<std::string, int> ExpectedCount, WordCount;
  for (const auto &Word: words)
    ++ExpectedCount[Word];
  const auto &EE = ExpectedCount.cend();
  typedef std::string::size_type SizeType;
  for (SizeType I = 0, IE = s.size() - Length + 1, Count; I != IE; ++I) {
    Count = 0;
    for (auto J = I, JE = I + Length; J != JE; J += Width) {
      auto Word = s.substr(J, Width);
      const auto EI = ExpectedCount.find(Word);
      if (EI == EE)
        break;
      auto &WC = WordCount[Word];
      if (WC >= EI->second)
        break;
      ++WC;
      ++Count;
    }
    if (Count == Size)
      Result.push_back(static_cast<int>(I));
    WordCount.clear();
  }
  return Result;
}
