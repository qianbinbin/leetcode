#include "ValidSudoku.h"

using namespace lcpp;

bool Solution36_1::isValidSudoku(std::vector<std::vector<char>> &board) {
  bool RowUsed[9][9]{}, ColUsed[9][9]{}, BlkUsed[9][9]{};
  for (int I = 0; I != 9; ++I) {
    for (int J = 0; J != 9; ++J) {
      const auto &Ch = board[I][J];
      if (Ch == '.')
        continue;
      const int Num = Ch - '1', B = I / 3 * 3 + J / 3;
      if (RowUsed[I][Num] || ColUsed[J][Num] || BlkUsed[B][Num])
        return false;
      RowUsed[I][Num] = true;
      ColUsed[J][Num] = true;
      BlkUsed[B][Num] = true;
    }
  }
  return true;
}
