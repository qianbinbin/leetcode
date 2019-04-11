#include "WordBreak.h"
#include <unordered_set>

using namespace lcpp;

bool Solution132_1::wordBreak(std::string s,
                              std::vector<std::string> &wordDict) {
  const auto &Size = s.size();
  const std::unordered_set<std::string> Set(wordDict.begin(), wordDict.end());
  const auto &SE = Set.end();
  std::vector<bool> DP(Size + 1);
  DP[0] = true;
  for (std::string::size_type Begin, End = 1, E = Size + 1; End != E; ++End) {
    for (Begin = End - 1; Begin != -1; --Begin) {
      if (DP[Begin] && Set.find(s.substr(Begin, End - Begin)) != SE) {
        DP[End] = true;
        break;
      }
    }
  }
  return DP[Size];
}
