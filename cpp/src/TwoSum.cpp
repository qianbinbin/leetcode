#include "TwoSum.h"
#include <cassert>
#include <unordered_map>

using namespace lcpp;

std::vector<int> Solution1_1::twoSum(std::vector<int> &nums, int target) {
  std::unordered_map<int, std::vector<int>::size_type> Map;
  for (std::vector<int>::size_type I = 0, E = nums.size(); I != E; ++I) {
    auto It = Map.find(target - nums[I]);
    if (It != Map.end())
      return {static_cast<int>(It->second), static_cast<int>(I)};
    Map.insert({nums[I], I});
  }
  assert(false && "No solution");
}
