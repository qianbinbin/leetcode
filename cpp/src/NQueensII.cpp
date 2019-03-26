#include "NQueensII.h"
#include <cassert>
#include <limits>
#include <vector>

using namespace lcpp;

typedef std::vector<bool> Mark;

static void solve(std::size_t I, std::size_t N, std::size_t &Count,
                  Mark &ColUsed, Mark &DgnUsed, Mark &AntiDgn) {
  if (I == N) {
    ++Count;
    return;
  }
  for (std::size_t J = 0; J != N; ++J) {
    const auto Dgn = J - I + N, Anti = I + J;
    if (ColUsed[J] || DgnUsed[Dgn] || AntiDgn[Anti])
      continue;
    ColUsed[J] = true;
    DgnUsed[Dgn] = true;
    AntiDgn[Anti] = true;
    solve(I + 1, N, Count, ColUsed, DgnUsed, AntiDgn);
    ColUsed[J] = false;
    DgnUsed[Dgn] = false;
    AntiDgn[Anti] = false;
  }
}

int Solution52_1::totalNQueens(int n) {
  assert(n > 0);
  const auto N = static_cast<std::size_t>(n);
  std::size_t Result = 0;
  Mark ColUsed(N), DgnUsed(2 * N - 1), AntiDgn(2 * N - 1);
  solve(0, N, Result, ColUsed, DgnUsed, AntiDgn);
  assert(Result <= std::numeric_limits<int>::max());
  return static_cast<int>(Result);
}
