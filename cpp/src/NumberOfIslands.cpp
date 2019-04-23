#include "NumberOfIslands.h"

using namespace lcpp;

#define LAND '1'
#define MARK '2'

typedef std::vector<std::vector<char>> GridType;
typedef GridType::size_type RowType;
typedef std::vector<char>::size_type ColType;

static void markIslands(GridType &Grid, RowType M, ColType N, RowType I,
                        ColType J) {
  Grid[I][J] = MARK;
  if (I != 0 && Grid[I - 1][J] == LAND)
    markIslands(Grid, M, N, I - 1, J);
  if (I != M - 1 && Grid[I + 1][J] == LAND)
    markIslands(Grid, M, N, I + 1, J);
  if (J != 0 && Grid[I][J - 1] == LAND)
    markIslands(Grid, M, N, I, J - 1);
  if (J != N - 1 && Grid[I][J + 1] == LAND)
    markIslands(Grid, M, N, I, J + 1);
}

int Solution200_1::numIslands(std::vector<std::vector<char>> &grid) {
  const auto &M = grid.size();
  if (M == 0)
    return 0;
  const auto &N = grid[0].size();
  if (N == 0)
    return 0;
  int Count = 0;
  for (RowType I = 0; I != M; ++I) {
    for (ColType J = 0; J != N; ++J) {
      if (grid[I][J] == LAND) {
        markIslands(grid, M, N, I, J);
        ++Count;
      }
    }
  }
  return Count;
}
