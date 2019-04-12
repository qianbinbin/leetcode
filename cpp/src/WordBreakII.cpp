#include "WordBreakII.h"
#include <unordered_set>

using namespace lcpp;

static std::string join(const std::vector<std::string> &Strings) {
  std::string Result;
  for (const auto &S : Strings)
    Result += S + ' ';
  if (!Result.empty())
    Result.pop_back();
  return Result;
}

static void wordBreak(const std::string &S, std::string::size_type I,
                      const std::vector<std::vector<bool>> &ValidWord,
                      std::vector<std::string> &Path,
                      std::vector<std::string> &Result) {
  const auto &Size = S.size();
  if (I == Size) {
    Result.push_back(join(Path));
    return;
  }
  for (std::string::size_type J = I; J != Size; ++J) {
    if (!ValidWord[I][J])
      continue;
    Path.emplace_back(S, I, J - I + 1);
    wordBreak(S, J + 1, ValidWord, Path, Result);
    Path.pop_back();
  }
}

std::vector<std::string>
Solution140_1::wordBreak(std::string s, std::vector<std::string> &wordDict) {
  const std::unordered_set<std::string> Set(wordDict.begin(), wordDict.end());
  const auto &SE = Set.end();
  const auto &Size = s.size();
  std::vector<bool> DP(Size + 1);
  DP[0] = true;
  std::vector<std::vector<bool>> ValidWord(Size, std::vector<bool>(Size + 1));
  for (std::string::size_type End = 1, E = Size + 1; End != E; ++End) {
    for (std::string::size_type Begin = End - 1; Begin != -1; --Begin) {
      if (DP[Begin] && Set.find(s.substr(Begin, End - Begin)) != SE) {
        DP[End] = true;
        ValidWord[Begin][End - 1] = true;
      }
    }
  }
  std::vector<std::string> Result;
  if (!DP[Size])
    return Result;
  std::vector<std::string> Path;
  ::wordBreak(s, 0, ValidWord, Path, Result);
  return Result;
}
