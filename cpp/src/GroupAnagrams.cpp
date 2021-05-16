#include "GroupAnagrams.h"
#include <algorithm>
#include <unordered_map>

using namespace lcpp;

static std::string sort(std::string const &Str) {
  auto S = Str;
  std::sort(S.begin(), S.end());
  return S;
}

std::vector<std::vector<std::string>>
Solution49_1::groupAnagrams(std::vector<std::string> &strs) {
  std::vector<std::vector<std::string>> Result;
  std::unordered_map<std::string, decltype(Result.size())> Index;
  for (auto &Str : strs) {
    auto S = sort(Str);
    auto It = Index.find(S);
    if (It == Index.end()) {
      Index[S] = Result.size();
      Result.push_back({Str});
    } else {
      Result[It->second].push_back(Str);
    }
  }
  return Result;
}
