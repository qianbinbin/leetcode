#include "SudokuSolver.h"
#include <array>
#include <cassert>

using namespace lcpp;

typedef std::array<std::array<bool, 9>, 9> Mark;

static bool solve(std::vector<std::vector<char>> &Board, int I, Mark &RowUsed,
                  Mark &ColUsed, Mark &BlkUsed) {
  for (int J, B, N; I != 9; ++I) {
    for (J = 0; J != 9; ++J) {
      auto &Ch = Board[I][J];
      if (Ch != '.')
        continue;
      B = I / 3 * 3 + J / 3;
      for (N = 0; N != 9; ++N) {
        if (RowUsed[I][N] || ColUsed[J][N] || BlkUsed[B][N])
          continue;
        Ch = N + '1';
        RowUsed[I][N] = true;
        ColUsed[J][N] = true;
        BlkUsed[B][N] = true;
        if (solve(Board, I, RowUsed, ColUsed, BlkUsed))
          return true;
        RowUsed[I][N] = false;
        ColUsed[J][N] = false;
        BlkUsed[B][N] = false;
      }
      Ch = '.';
      return false;
    }
  }
  return true;
}

void Solution37_1::solveSudoku(std::vector<std::vector<char>> &board) {
  Mark RowUsed{}, ColUsed{}, BlkUsed{};
  for (int I = 0, J, N; I != 9; ++I) {
    for (J = 0; J != 9; ++J) {
      auto const &Ch = board[I][J];
      if (Ch == '.')
        continue;
      N = Ch - '1';
      RowUsed[I][N] = true;
      ColUsed[J][N] = true;
      BlkUsed[I / 3 * 3 + J / 3][N] = true;
    }
  }
  assert(solve(board, 0, RowUsed, ColUsed, BlkUsed));
}
