#include "WordSearch.h"

using namespace lcpp;

template <typename T> using Vec2D = std::vector<std::vector<T>>;

static bool exist(Vec2D<char> &Board, Vec2D<char>::size_type I,
                  Vec2D<char>::size_type J, Vec2D<bool> &Visited,
                  std::string::iterator It, std::string::iterator E) {
  if (It == E)
    return true;
  if (I >= Board.size() || J >= Board[0].size() || Visited[I][J] ||
      Board[I][J] != *It)
    return false;
  Visited[I][J] = true;
  bool result = exist(Board, I - 1, J, Visited, It + 1, E) ||
                exist(Board, I + 1, J, Visited, It + 1, E) ||
                exist(Board, I, J - 1, Visited, It + 1, E) ||
                exist(Board, I, J + 1, Visited, It + 1, E);
  Visited[I][J] = false;
  return result;
}

bool Solution79_1::exist(Vec2D<char> &board, std::string word) {
  const auto &M = board.size();
  const auto &N = board[0].size();

  Vec2D<bool> Visited(M, std::vector<bool>(N));
  for (Vec2D<char>::size_type I = 0; I != M; ++I) {
    for (std::vector<char>::size_type J = 0; J != N; ++J) {
      if (::exist(board, I, J, Visited, word.begin(), word.end()))
        return true;
    }
  }
  return false;
}
