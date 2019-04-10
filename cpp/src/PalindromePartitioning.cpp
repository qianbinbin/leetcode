#include "PalindromePartitioning.h"

using namespace lcpp;

static void partition(const std::string &S, std::string::size_type I,
                      const std::vector<std::vector<bool>> &Dp,
                      std::vector<std::vector<std::string>> &Result,
                      std::vector<std::string> &Path) {
  if (I == S.size()) {
    Result.push_back(Path);
    return;
  }
  for (std::string::size_type L = 1, E = S.size() - I + 1; L != E; ++L) {
    if (!Dp[I][L])
      continue;
    Path.emplace_back(S, I, L);
    partition(S, I + L, Dp, Result, Path);
    Path.pop_back();
  }
}

std::vector<std::vector<std::string>> Solution131_1::partition(std::string s) {
  const auto &Size = s.size();
  std::vector<std::vector<bool>> Dp(Size, std::vector<bool>(Size + 1));
  for (std::string::size_type I = Size - 1, IE = -1; I != IE; --I) {
    const auto &Ch = s[I];
    Dp[I][0] = true;
    Dp[I][1] = true;
    for (std::string::size_type L = 2, LE = Size - I + 1; L != LE; ++L)
      if (Ch == s[I + L - 1] && Dp[I + 1][L - 2])
        Dp[I][L] = true;
  }
  std::vector<std::vector<std::string>> Result;
  std::vector<std::string> Path;
  ::partition(s, 0, Dp, Result, Path);
  return Result;
}
