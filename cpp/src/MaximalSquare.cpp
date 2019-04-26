#include "MaximalSquare.h"

using namespace lcpp;

typedef std::vector<std::vector<int>>::size_type RowType;
typedef std::vector<int>::size_type ColType;

int Solution221_1::maximalSquare(std::vector<std::vector<char>> &matrix) {
  const auto &M = matrix.size();
  if (M == 0)
    return 0;
  const auto &N = matrix[0].size();
  if (N == 0)
    return 0;
  std::vector<int> DP(N);
  int MaxSideLen = 0;
  for (ColType J = 0; J != N; ++J) {
    if (matrix[0][J] == '1')
      DP[J] = MaxSideLen = 1;
  }
  int Prev, Tmp;
  for (RowType I = 1; I != M; ++I) {
    const auto &Row = matrix[I];
    Prev = DP[0];
    MaxSideLen = std::max(MaxSideLen, DP[0] = Row[0] == '1' ? 1 : 0);
    for (ColType J = 1; J != N; ++J) {
      Tmp = DP[J];
      if (Row[J] == '1')
        MaxSideLen = std::max(
            MaxSideLen, DP[J] = std::min(Prev, std::min(DP[J - 1], DP[J])) + 1);
      else
        DP[J] = 0;
      Prev = Tmp;
    }
  }
  return MaxSideLen * MaxSideLen;
}
