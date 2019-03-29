#include "WildcardMatching.h"
#include <vector>

using namespace lcpp;

bool Solution44_1::isMatch(std::string s, std::string p) {
  const auto &M = s.size(), &N = p.size();
  std::vector<std::vector<bool>> Match(M + 1, std::vector<bool>(N + 1));
  Match[0][0] = true;
  for (std::vector<bool>::size_type J = 1;
       J <= N && Match[0][J - 1] && p[J - 1] == '*'; ++J)
    Match[0][J] = true;
  char Ch;
  for (std::vector<std::vector<bool>>::size_type I = 1; I <= M; ++I) {
    for (std::vector<bool>::size_type J = 1; J <= N; ++J) {
      if ((Ch = p[J - 1]) == '*')
        Match[I][J] = Match[I][J - 1] || Match[I - 1][J];
      else if (Ch == '?' || Ch == s[I - 1])
        Match[I][J] = Match[I - 1][J - 1];
    }
  }
  return Match[M][N];
}
