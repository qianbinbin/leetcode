#include "ScrambleString.h"

#include <unordered_map>
#include <vector>

using namespace lcpp;

typedef std::string::size_type SizeType;

static bool isScramble(std::string S1, std::string S2,
                       std::unordered_map<std::string, bool> &Map) {
  std::string Key = S1 + S2;
  if (Map.find(Key) != Map.end())
    return Map[Key];
  auto L = S1.size();
  if (L == 1) {
    return Map[Key] = S1 == S2;
  }
  SizeType Count[26]{0};
  for (SizeType K = 0; K != L; ++K) {
    ++Count[S1[K] - 'a'];
    --Count[S2[K] - 'a'];
  }
  for (const auto &C : Count) {
    if (C != 0)
      return Map[Key] = false;
  }
  for (SizeType K = 1; K != L; ++K) {
    if ((isScramble(S1.substr(0, K), S2.substr(0, K), Map) &&
         isScramble(S1.substr(K, L - K), S2.substr(K, L - K), Map)) ||
        (isScramble(S1.substr(0, K), S2.substr(L - K, K), Map) &&
         isScramble(S1.substr(K, L - K), S2.substr(0, L - K), Map)))
      return Map[Key] = true;
  }
  return Map[Key] = false;
}

bool Solution87_1::isScramble(std::string s1, std::string s2) {
  std::unordered_map<std::string, bool> Map;
  return ::isScramble(s1, s2, Map);
}

bool Solution87_2::isScramble(std::string s1, std::string s2) {
  const auto &Size = s1.size();
  std::vector<std::vector<std::vector<bool>>> Dp(
      Size, std::vector<std::vector<bool>>(Size, std::vector<bool>(Size)));
  for (SizeType I = 0; I != Size; ++I) {
    for (SizeType J = 0; J != Size; ++J) {
      if (s1[I] == s2[J])
        Dp[0][I][J] = true;
    }
  }
  for (SizeType L = 1; L != Size; ++L) { // length = L + 1
    for (SizeType I = 0, E = Size - L; I != E; ++I) {
      for (SizeType J = 0; J != E; ++J) {
        for (SizeType K = 0; K != L; ++K) {
          if ((Dp[K][I][J] && Dp[L - K - 1][I + K + 1][J + K + 1]) ||
              (Dp[K][I][J + L - K] && Dp[L - K - 1][I + K + 1][J])) {
            Dp[L][I][J] = true;
            break;
          }
        }
      }
    }
  }
  return Dp[Size - 1][0][0];
}
