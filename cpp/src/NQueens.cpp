#include "NQueens.h"
#include <cassert>

using namespace lcpp;

typedef std::vector<std::string> BoardType;
typedef std::vector<BoardType> BoardVec;
typedef std::vector<bool> Mark;

static void solve(BoardType::size_type I, BoardType::size_type N,
                  Mark &ColUsed, Mark &DgnUsed, Mark &AntiDgn,
                  BoardType &Path, BoardVec &Result) {
  if (I == N) {
    Result.push_back(Path);
    return;
  }
  for (BoardType::size_type J = 0; J != N; ++J) {
    const auto Dgn = J - I + N, Anti = I + J;
    if (ColUsed[J] || DgnUsed[Dgn] || AntiDgn[Anti])
      continue;
    ColUsed[J] = true;
    DgnUsed[Dgn] = true;
    AntiDgn[Anti] = true;
    Path[I][J] = 'Q';
    solve(I + 1, N, ColUsed, DgnUsed, AntiDgn, Path, Result);
    Path[I][J] = '.';
    ColUsed[J] = false;
    DgnUsed[Dgn] = false;
    AntiDgn[Anti] = false;
  }
}

std::vector<std::vector<std::string>> Solution51_1::solveNQueens(int n) {
  assert(n > 0);
  const auto N = static_cast<BoardType::size_type>(n);
  Mark ColUsed(N), DgnUsed(2 * N - 1), AntiDgn(2 * N - 1);
  BoardVec Result;
  BoardType Path(N, std::string(N, '.'));
  solve(0, N, ColUsed, DgnUsed, AntiDgn, Path, Result);
  return Result;
}
