#include "LongestCommonPrefix.h"

using namespace lcpp;

std::string Solution14_1::longestCommonPrefix(std::vector<std::string> &strs) {
  if (strs.empty())
    return "";
  std::string Prefix;
  for (std::string::size_type J = 0, Size = strs[0].size(); J != Size; ++J) {
    const auto &Ch = strs[0][J];
    for (auto It = strs.cbegin() + 1, E = strs.cend(); It != E; ++It) {
      if (J >= (*It).size() || (*It)[J] != Ch)
        return Prefix;
    }
    Prefix += Ch;
  }
  return Prefix;
}
