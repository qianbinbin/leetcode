#include "Subsets.h"

using namespace lcpp;

static void subsets(std::vector<int>::iterator I, std::vector<int>::iterator E,
                    std::vector<int> &Path,
                    std::vector<std::vector<int>> &Result) {
  Result.push_back(Path);
  for (; I != E; ++I) {
    Path.push_back(*I);
    subsets(I + 1, E, Path, Result);
    Path.pop_back();
  }
}

std::vector<std::vector<int>> Solution78_1::subsets(std::vector<int> &nums) {
  std::vector<std::vector<int>> Result;
  std::vector<int> Path;
  ::subsets(nums.begin(), nums.end(), Path, Result);
  return Result;
}
