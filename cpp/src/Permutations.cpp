#include "Permutations.h"

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
  for (std::vector<int>::size_type I = 0; I != E; ++I) {
    if (Visited[I])
      continue;
    Path.push_back(Nums[I]);
    Visited[I] = true;
    permute(Nums, Visited, Path, Result);
    Visited[I] = false;
    Path.pop_back();
  }
}

std::vector<std::vector<int>> Solution46_1::permute(std::vector<int> &nums) {
  std::vector<std::vector<int>> Result;
  std::vector<int> Path;
  std::vector<bool> Visited(nums.size());
  ::permute(nums, Visited, Path, Result);
  return Result;
}
