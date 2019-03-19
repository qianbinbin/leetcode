#include "LongestSubstringWithoutRepeatingCharacters.h"
#include <unordered_map>

using namespace lcpp;

int Solution3_1::lengthOfLongestSubstring(std::string s) {
  std::unordered_map<char, std::string::size_type> Map;
  std::string::size_type Longest = 0, Start = 0, I, E = s.size();
  for (I = 0; I != E; ++I) {
    auto It = Map.find(s[I]);
    if (It != Map.end() && It->second >= Start) {
      Longest = std::max(Longest, I - Start);
      Start = It->second + 1;
      It->second = I;
    } else {
      Map[s[I]] = I;
    }
  }
  Longest = std::max(Longest, I - Start);
  return static_cast<int>(Longest);
}
