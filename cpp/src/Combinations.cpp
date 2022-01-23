#include "Combinations.h"

using namespace lcpp;

static void combine(int N, int K, int I, std::vector<int> &Path,
                    std::vector<std::vector<int>> &Result) {
  if (Path.size() == K) {
    Result.push_back(Path);
    return;
  }
  for (int E = N - K + Path.size() + 1; I <= E; ++I) {
    Path.push_back(I);
    combine(N, K, I + 1, Path, Result);
    Path.pop_back();
  }
}

std::vector<std::vector<int>> Solution77_1::combine(int n, int k) {
  std::vector<std::vector<int>> Result;
  std::vector<int> Path;
  ::combine(n, k, 1, Path, Result);
  return Result;
}
