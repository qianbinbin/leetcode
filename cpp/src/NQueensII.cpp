#include "NQueensII.h"
#include <vector>

using namespace lcpp;

typedef std::vector<bool> Mark;

static void solve(int I, int N, int &Count, Mark &ColUsed, Mark &DiagUsed,
                  Mark &AntiDiag) {
  if (I == N) {
    ++Count;
    return;
  }
  for (int J = 0, D, A; J != N; ++J) {
    D = I - J + N - 1;
    A = I + J;
    if (ColUsed[J] || DiagUsed[D] || AntiDiag[A])
      continue;
    ColUsed[J] = true;
    DiagUsed[D] = true;
    AntiDiag[A] = true;
    solve(I + 1, N, Count, ColUsed, DiagUsed, AntiDiag);
    ColUsed[J] = false;
    DiagUsed[D] = false;
    AntiDiag[A] = false;
  }
}

int Solution52_1::totalNQueens(int n) {
  int Result = 0;
  Mark ColUsed(n), DgnUsed(2 * n - 1), AntiDgn(2 * n - 1);
  solve(0, n, Result, ColUsed, DgnUsed, AntiDgn);
  return Result;
}
