#include "CombinationSumII.h"
#include <algorithm>

using namespace lcpp;

typedef std::vector<int> Vec;
typedef std::vector<std::vector<int>> Vec2D;

static void combination(Vec::iterator I, Vec::iterator E, int Target, Vec &Path,
                        int Sum, Vec2D &Result) {
  if (Sum == Target) {
    Result.push_back(Path);
    return;
  }
  for (int Last = -1, Diff = Target - Sum; I != E && *I <= Diff; ++I) {
    if (*I == Last)
      continue;
    Last = *I;
    Path.push_back(Last);
    combination(I + 1, E, Target, Path, Sum + Last, Result);
    Path.pop_back();
  }
}

Vec2D Solution40_1::combinationSum2(Vec &candidates, int target) {
  std::sort(candidates.begin(), candidates.end());
  Vec2D Result;
  Vec Path;
  combination(candidates.begin(), candidates.end(), target, Path, 0, Result);
  return Result;
}
