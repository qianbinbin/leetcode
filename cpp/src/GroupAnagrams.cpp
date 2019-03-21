#include "GroupAnagrams.h"
#include <array>
#include <map>

using namespace lcpp;

typedef std::string::size_type SizeType;

std::vector<std::vector<std::string>>
Solution49_1::groupAnagrams(std::vector<std::string> &strs) {
  typedef std::array<SizeType, 26> Anagram;
  std::map<Anagram, std::vector<std::string>> Map;
  for (const auto &Str : strs) {
    Anagram A{};
    for (const auto Ch : Str)
      ++A[Ch - 'a'];
    Map[A].push_back(Str);
  }
  std::vector<std::vector<std::string>> Result;
  Result.reserve(Map.size());
  for (const auto &Pair : Map)
    Result.push_back(Pair.second);
  return Result;
}
