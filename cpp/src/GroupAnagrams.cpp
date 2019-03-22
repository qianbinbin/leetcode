#include "GroupAnagrams.h"
#include <array>
#include <map>
#include <unordered_map>

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

class Anagram {
private:
  std::array<SizeType, 26> Count{};
  std::size_t Hash;

public:
  explicit Anagram(const std::string &S) {
    for (auto Ch : S)
      ++Count[Ch - 'a'];
    std::string Tmp;
    char Ch = 'a';
    for (auto C : Count)
      Tmp += std::string(C, Ch++);
    Hash = std::hash<std::string>()(Tmp);
  }

  std::size_t hashCode() const {
    return Hash;
  }

  inline bool operator==(const Anagram &A) const {
    if (this == &A)
      return true;
    if (Hash != A.Hash)
      return false;
    return std::equal(Count.begin(), Count.end(), A.Count.begin());
  }
};

namespace std {

template<> struct hash<Anagram> {
  std::size_t operator()(const Anagram &A) const {
    return A.hashCode();
  }
};

}

std::vector<std::vector<std::string>>
Solution49_2::groupAnagrams(std::vector<std::string> &strs) {
  std::unordered_map<Anagram, std::vector<std::string>> Map;
  for (const auto &Str : strs)
    Map[Anagram(Str)].push_back(Str);
  std::vector<std::vector<std::string>> Result;
  Result.reserve(Map.size());
  for (const auto &Pair : Map)
    Result.push_back(Pair.second);
  return Result;
}
