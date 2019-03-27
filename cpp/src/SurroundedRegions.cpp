#include "SurroundedRegions.h"

using namespace lcpp;

typedef std::vector<std::vector<char>> BoardType;
typedef std::vector<char>::size_type SizeType;

static void mark(BoardType &Board, SizeType I, SizeType J) {
  Board[I][J] = 'M';
  if (I != 0 && Board[I - 1][J] == 'O')
    mark(Board, I - 1, J);
  if (I != Board.size() - 1 && Board[I + 1][J] == 'O')
    mark(Board, I + 1, J);
  if (J != 0 && Board[I][J - 1] == 'O')
    mark(Board, I, J - 1);
  if (J != Board[I].size() - 1 && Board[I][J + 1] == 'O')
    mark(Board, I, J + 1);
}

void Solution130_1::solve(BoardType &board) {
  const auto &M = board.size();
  if (M == 0)
    return;
  const auto &N = board[0].size();
  if (N == 0)
    return;
  for (SizeType J = 0; J != N; ++J) {
    if (board[0][J] == 'O')
      mark(board, 0, J);
    if (board[M - 1][J] == 'O')
      mark(board, M - 1, J);
  }
  for (SizeType I = 1, E = M - 1; I < E; ++I) {
    if (board[I][0] == 'O')
      mark(board, I, 0);
    if (board[I][N - 1] == 'O')
      mark(board, I, N - 1);
  }
  for (SizeType I = 1, IE = M - 1; I < IE; ++I) {
    for (SizeType J = 1, JE = N - 1; J < JE; ++J) {
      if (board[I][J] == 'O')
        board[I][J] = 'X';
    }
  }
  for (auto &Row : board) {
    for (auto &Ch : Row) {
      if (Ch == 'M')
        Ch = 'O';
    }
  }
}
