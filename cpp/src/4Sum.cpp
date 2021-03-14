#include "4Sum.h"
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace lcpp;

std::vector<std::vector<int>> Solution18_1::fourSum(std::vector<int> &nums,
                                                    int target) {
  std::vector<std::vector<int>> Result;
  if (nums.size() < 4)
    return Result;
  std::sort(nums.begin(), nums.end());
  for (auto I1 = nums.begin(), E1 = nums.end() - 3; I1 != E1;) {
    for (auto I2 = I1 + 1, E2 = nums.end() - 2; I2 != E2;) {
      auto Target = target - *I1 - *I2;
      auto I3 = I2 + 1, I4 = nums.end() - 1;
      while (I3 < I4) {
        auto Sum = *I3 + *I4;
        if (Sum < Target) {
          do {
            ++I3;
          } while (I3 != I4 && *I3 == *(I3 - 1));
        } else if (Sum > Target) {
          do {
            --I4;
          } while (I3 != I4 && *I4 == *(I4 + 1));
        } else {
          Result.push_back({*I1, *I2, *I3, *I4});
          do {
            ++I3;
          } while (I3 < I4 && *I3 == *(I3 - 1));
          do {
            --I4;
          } while (I3 < I4 && *I4 == *(I4 + 1));
        }
      }
      do {
        ++I2;
      } while (I2 != E2 && *I2 == *(I2 - 1));
    }
    do {
      ++I1;
    } while (I1 != E1 && *I1 == *(I1 - 1));
  }
  return Result;
}

std::vector<std::vector<int>> Solution18_2::fourSum(std::vector<int> &nums,
                                                    int target) {
  std::vector<std::vector<int>> Result;
  if (nums.size() < 4)
    return Result;
  std::set<std::vector<int>> Set;
  typedef std::vector<int>::size_type SizeType;
  std::unordered_map<int, std::vector<std::pair<SizeType, SizeType>>> Map;
  for (SizeType I = 0, E = nums.size(); I != E; ++I) {
    for (auto J = I + 1; J != E; ++J)
      Map[nums[I] + nums[J]].push_back({I, J});
  }
  for (auto I = Map.begin(), E = Map.end(); I != E; ++I) {
    auto J = Map.find(target - I->first);
    if (J == E)
      continue;
    for (const auto &Pair1 : I->second) {
      for (const auto &Pair2 : J->second) {
        if (Pair1.first == Pair2.first || Pair1.first == Pair2.second ||
            Pair1.second == Pair2.first || Pair1.second == Pair2.second)
          continue;
        std::vector<int> Quadruplet{nums[Pair1.first], nums[Pair1.second],
                                    nums[Pair2.first], nums[Pair2.second]};
        std::sort(Quadruplet.begin(), Quadruplet.end());
        Set.insert(std::move(Quadruplet));
      }
    }
  }
  Result.assign(Set.begin(), Set.end());
  return Result;
}
