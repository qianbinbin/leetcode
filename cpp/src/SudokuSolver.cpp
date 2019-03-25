#include "SudokuSolver.h"
#include <array>
#include <cassert>

using namespace lcpp;

typedef std::array<std::array<bool, 9>, 9> Mark;

static bool solve(std::vector<std::vector<char>> &Board, int I,
                  Mark &RowUsed, Mark &ColUsed, Mark &BlkUsed) {
  for (; I != 9; ++I) {
    for (int J = 0; J != 9; ++J) {
      if (Board[I][J] != '.')
        continue;
      const auto B = I / 3 * 3 + J / 3;
      for (int N = 0; N != 9; ++N) {
        if (RowUsed[I][N] || ColUsed[J][N] || BlkUsed[B][N])
          continue;
        Board[I][J] = static_cast<char>(N + '1');
        RowUsed[I][N] = true;
        ColUsed[J][N] = true;
        BlkUsed[B][N] = true;
        if (solve(Board, I, RowUsed, ColUsed, BlkUsed))
          return true;
        RowUsed[I][N] = false;
        ColUsed[J][N] = false;
        BlkUsed[B][N] = false;
      }
      Board[I][J] = '.';
      return false;
    }
  }
  return true;
}

void Solution37_1::solveSudoku(std::vector<std::vector<char>> &board) {
  Mark RowUsed{}, ColUsed{}, BlkUsed{};
  for (int I = 0; I != 9; ++I) {
    for (int J = 0; J != 9; ++J) {
      const auto &Ch = board[I][J];
      if (Ch == '.')
        continue;
      const int N = Ch - '1';
      RowUsed[I][N] = true;
      ColUsed[J][N] = true;
      BlkUsed[I / 3 * 3 + J / 3][N] = true;
    }
  }
  assert(solve(board, 0, RowUsed, ColUsed, BlkUsed));
}
