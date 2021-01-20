#include "LongestSubstringWithoutRepeatingCharacters.h"
#include <array>

using namespace lcpp;

int Solution3_1::lengthOfLongestSubstring(std::string s) {
  std::array<std::string::difference_type, 128> Map{};
  Map.fill(-1);
  std::string::difference_type Pre = -1, I, Len = 0, E = s.size();
  for (I = 0; I != E; ++I) {
    auto &Idx = Map[s[I]];
    Pre = std::max(Pre, Idx);
    Len = std::max(Len, I - Pre);
    Idx = I;
  }
  return Len;
}
