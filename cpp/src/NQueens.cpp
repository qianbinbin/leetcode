#include "NQueens.h"

using namespace lcpp;

typedef std::vector<std::string> BoardType;
typedef std::vector<bool> Mark;

static void solve(BoardType::size_type I, BoardType::size_type N, Mark &ColUsed,
                  Mark &DiagUsed, Mark &AntiDiag, BoardType &Path,
                  std::vector<BoardType> &Result) {
  if (I == N) {
    Result.push_back(Path);
    return;
  }
  for (BoardType::size_type J = 0, D, A; J != N; ++J) {
    D = I - J + N - 1;
    A = I + J;
    if (ColUsed[J] || DiagUsed[D] || AntiDiag[A])
      continue;
    ColUsed[J] = true;
    DiagUsed[D] = true;
    AntiDiag[A] = true;
    Path[I][J] = 'Q';
    solve(I + 1, N, ColUsed, DiagUsed, AntiDiag, Path, Result);
    Path[I][J] = '.';
    ColUsed[J] = false;
    DiagUsed[D] = false;
    AntiDiag[A] = false;
  }
}

std::vector<std::vector<std::string>> Solution51_1::solveNQueens(int n) {
  Mark ColUsed(n), DgnUsed(2 * n - 1), AntiDgn(2 * n - 1);
  std::vector<BoardType> Result;
  BoardType Path(n, std::string(n, '.'));
  solve(0, n, ColUsed, DgnUsed, AntiDgn, Path, Result);
  return Result;
}
