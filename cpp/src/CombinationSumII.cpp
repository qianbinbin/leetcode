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
  while (I != E) {
    if (Sum + *I > Target)
      break;
    Path.push_back(*I);
    combination(I + 1, E, Target, Path, Sum + *I, Result);
    Path.pop_back();
    do {
      ++I;
    } while (I != E && *I == *(I - 1));
  }
}

Vec2D Solution40_1::combinationSum2(Vec &candidates, int target) {
  std::sort(candidates.begin(), candidates.end());
  Vec2D Result;
  Vec Path;
  combination(candidates.begin(), candidates.end(), target, Path, 0, Result);
  return Result;
}
