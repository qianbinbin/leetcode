#include "SubsetsII.h"
#include <algorithm>

using namespace lcpp;

static void subsets(std::vector<int>::iterator I,
                    std::vector<int>::iterator E,
                    std::vector<int> &Path,
                    std::vector<std::vector<int>> &Result) {
  Result.push_back(Path);
  int *Last = nullptr;
  for (; I != E; ++I) {
    if (Last != nullptr && *Last == *I)
      continue;
    Last = &*I;
    Path.push_back(*I);
    subsets(I + 1, E, Path, Result);
    Path.pop_back();
  }
}

std::vector<std::vector<int>> Solution90_1::subsetsWithDup(std::vector<int> &nums) {
  std::sort(nums.begin(), nums.end());
  std::vector<std::vector<int>> Result;
  std::vector<int> Path;
  subsets(nums.begin(), nums.end(), Path, Result);
  return Result;
}
