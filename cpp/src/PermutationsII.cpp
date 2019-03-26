#include "PermutationsII.h"
#include <algorithm>

using namespace lcpp;

static void permute(std::vector<int> &Nums,
                    std::vector<bool> &Visited,
                    std::vector<int> &Path,
                    std::vector<std::vector<int>> &Result) {
  const auto &E = Nums.size();
  if (Path.size() == E) {
    Result.push_back(Path);
    return;
  }
  int *Last = nullptr;
  for (std::vector<int>::size_type I = 0; I != E; ++I) {
    if (Visited[I] || (Last != nullptr && *Last == Nums[I]))
      continue;
    Last = &Nums[I];
    Path.push_back(Nums[I]);
    Visited[I] = true;
    permute(Nums, Visited, Path, Result);
    Visited[I] = false;
    Path.pop_back();
  }
}

std::vector<std::vector<int>> Solution47_1::permuteUnique(std::vector<int> &nums) {
  std::vector<std::vector<int>> Result;
  std::vector<int> Path;
  std::vector<bool> Visited(nums.size());
  std::sort(nums.begin(), nums.end());
  permute(nums, Visited, Path, Result);
  return Result;
}
