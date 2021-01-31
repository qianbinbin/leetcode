#include "LongestCommonPrefix.h"

using namespace lcpp;

std::string Solution14_1::longestCommonPrefix(std::vector<std::string> &strs) {
  if (strs.empty())
    return "";
  std::string::size_type J = 0, N = strs[0].size();
  std::vector<std::string>::size_type I, M = strs.size();
  for (; J != N; ++J) {
    const auto &Ch = strs[0][J];
    for (I = 1; I != M; ++I) {
      if (J >= strs[I].size() || strs[I][J] != Ch)
        return strs[0].substr(0, J);
    }
  }
  return strs[0];
}
