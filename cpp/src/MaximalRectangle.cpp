#include "MaximalRectangle.h"
#include <cassert>
#include <limits>
#include <stack>

using namespace lcpp;

int Solution85_1::maximalRectangle(std::vector<std::vector<char>> &matrix) {
  const auto &M = matrix.size();
  if (M == 0)
    return 0;
  const auto &N = matrix[0].size();
  if (N == 0)
    return 0;
  typedef std::vector<std::vector<char>>::size_type RowType;
  typedef std::vector<char>::size_type ColumnType;
  std::vector<ColumnType> First(N, 0);
  std::vector<ColumnType> Last(N, N);
  std::vector<RowType> Height(N, 0);
  ColumnType Start, End, J, RE = static_cast<ColumnType>(0) - 1;
  decltype(M * N) Largest = 0;
  for (const auto &Row : matrix) {
    Start = 0;
    for (J = 0; J != N; ++J) {
      if (Row[J] == '1') {
        if (Start > First[J])
          First[J] = Start;
        ++Height[J];
      } else {
        Start = J + 1;
        First[J] = 0;
        Height[J] = 0;
      }
    }
    End = N;
    for (J = N - 1; J != RE; --J) {
      if (Row[J] == '1') {
        if (End < Last[J])
          Last[J] = End;
        Largest = std::max(Largest, Height[J] * (Last[J] - First[J]));
      } else {
        End = J;
        Last[J] = N;
      }
    }
  }
  assert(Largest <= std::numeric_limits<int>::max() && "Result overflow!");
  return static_cast<int>(Largest);
}

int Solution85_2::maximalRectangle(std::vector<std::vector<char>> &matrix) {
  const auto &M = matrix.size();
  if (M == 0)
    return 0;
  const auto &N = matrix[0].size();
  if (N == 0)
    return 0;
  decltype(M * N) Largest = 0, Area;
  typedef std::vector<std::vector<char>>::size_type RowType;
  typedef std::vector<char>::size_type ColumnType;
  std::vector<RowType> Height(N, 0);
  std::stack<ColumnType> Stack;
  ColumnType I, J;
  for (const auto &Row : matrix) {
    for (I = 0; I != N; ++I) {
      if (Row[I] == '1')
        ++Height[I];
      else
        Height[I] = 0;
      while (!Stack.empty() && Height[I] < Height[J = Stack.top()]) {
        Stack.pop();
        Area = Height[J] * (Stack.empty() ? I : I - Stack.top() - 1);
        if (Area > Largest)
          Largest = Area;
      }
      Stack.push(I);
    }
    while (!Stack.empty()) {
      J = Stack.top();
      Stack.pop();
      Area = Height[J] * (Stack.empty() ? N : N - Stack.top() - 1);
      if (Area > Largest)
        Largest = Area;
    }
  }
  assert(Largest <= std::numeric_limits<int>::max() && "Result overflow!");
  return static_cast<int>(Largest);
}
