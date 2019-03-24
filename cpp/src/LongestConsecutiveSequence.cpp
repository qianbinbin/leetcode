#include "LongestConsecutiveSequence.h"
#include <cassert>
#include <unordered_map>
#include <unordered_set>

using namespace lcpp;

int Solution128_1::longestConsecutive(std::vector<int> &nums) {
  int Longest = 0, I;
  std::unordered_set<int> Set(nums.begin(), nums.end());
  const auto &E = Set.cend();
  for (const auto &N : nums) {
    if (Set.find(N - 1) == E) {
      for (I = N + 1; Set.find(I) != E; ++I);
      Longest = std::max(Longest, I - N);
    }
  }
  return Longest;
}

class UnionFind {
  std::vector<std::size_t> Parent;
  std::vector<std::size_t> Rank;

public:
  explicit UnionFind(std::size_t Size) : Parent(Size), Rank(Size) {
    assert(Size > 0);
    std::size_t P = 0;
    for (auto &I : Parent)
      I = P++;
  }

  std::size_t find(std::size_t I) {
    if (I == Parent[I])
      return I;
    return Parent[I] = find(Parent[I]);
  }

  void join(std::size_t I1, std::size_t I2) {
    auto R1 = find(I1), R2 = find(I2);
    if (R1 == R2)
      return;
    if (Rank[R1] < Rank[R2]) {
      Parent[R1] = R2;
    } else {
      Parent[R2] = R1;
      if (Rank[R1] == Rank[R2])
        ++Rank[R1];
    }
  }

  std::size_t maxSetSize() {
    std::size_t Max = 1;
    std::vector<std::size_t> Size(Parent.size());
    for (std::size_t I = 0, E = Parent.size(); I != E; ++I)
      Max = std::max(Max, ++Size[find(I)]);
    return Max;
  }
};

int Solution128_2::longestConsecutive(std::vector<int> &nums) {
  const auto &Size = nums.size();
  if (Size == 0)
    return 0;
  UnionFind Uf(Size);
  std::unordered_map<int, std::size_t> Map;
  for (std::vector<int>::size_type I = 0; I != Size; ++I) {
    const auto &N = nums[I];
    auto It = Map.find(N), ME = Map.end();
    if (It != Map.end())
      continue;
    Map[N] = I;
    auto Left = Map.find(N - 1);
    if (Left != ME)
      Uf.join(Left->second, I);
    auto Right = Map.find(N + 1);
    if (Right != ME)
      Uf.join(I, Right->second);
  }
  return static_cast<int>(Uf.maxSetSize());
}
