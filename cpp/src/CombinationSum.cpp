#include "CombinationSum.h"

using namespace lcpp;

typedef std::vector<int> Vec;
typedef std::vector<Vec> Vec2D;

static void combination(Vec::iterator I, Vec::iterator E, int Target,
                        Vec &Path, int Sum, Vec2D &Result) {
  if (Sum == Target) {
    Result.push_back(Path);
    return;
  }
  for (; I != E; ++I) {
    if (Sum + *I > Target)
      continue;
    Path.push_back(*I);
    combination(I, E, Target, Path, Sum + *I, Result);
    Path.pop_back();
  }
}

Vec2D Solution39_1::combinationSum(Vec &candidates, int target) {
  Vec2D Result;
  Vec Path;
  combination(candidates.begin(), candidates.end(), target, Path, 0, Result);
  return Result;
}
