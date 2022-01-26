#include "MaximalRectangle.h"
#include <stack>

using namespace lcpp;

int Solution85_1::maximalRectangle(std::vector<std::vector<char>> &matrix) {
  const auto &M = matrix.size();
  const auto &N = matrix[0].size();
  typedef std::vector<std::vector<char>>::size_type RowType;
  typedef std::vector<char>::size_type ColumnType;
  std::vector<ColumnType> First(N, 0);
  std::vector<ColumnType> Last(N, N);
  std::vector<RowType> Height(N, 0);
  ColumnType Start, End, J, RE = static_cast<ColumnType>(0) - 1;
  decltype(M * N) Result = 0;
  for (const auto &Row : matrix) {
    Start = 0;
    for (J = 0; J != N; ++J) {
      if (Row[J] == '0') {
        Start = J + 1;
        First[J] = 0;
        Height[J] = 0;
      } else {
        First[J] = std::max(First[J], Start);
        ++Height[J];
      }
    }
    End = N;
    for (J = N - 1; J != RE; --J) {
      if (Row[J] == '0') {
        End = J;
        Last[J] = N;
      } else {
        Last[J] = std::min(Last[J], End);
        Result = std::max(Result, Height[J] * (Last[J] - First[J]));
      }
    }
  }
  return static_cast<int>(Result);
}

int Solution85_2::maximalRectangle(std::vector<std::vector<char>> &matrix) {
  const auto &M = matrix.size();
  const auto &N = matrix[0].size();
  typedef std::vector<std::vector<char>>::size_type RowType;
  typedef std::vector<char>::size_type ColumnType;
  std::vector<RowType> Height(N, 0);
  std::stack<ColumnType> Stack;
  ColumnType J, K, Left;
  decltype(M * N) Result = 0;
  for (const auto &Row : matrix) {
    for (J = 0; J != N; ++J) {
      Height[J] = Row[J] == '0' ? 0 : Height[J] + 1;
      while (!Stack.empty() && Height[J] <= Height[K = Stack.top()]) {
        Stack.pop();
        Left = Stack.empty() ? 0 : Stack.top() + 1;
        Result = std::max(Result, Height[K] * (J - Left));
      }
      Stack.push(J);
    }
    while (!Stack.empty()) {
      K = Stack.top();
      Stack.pop();
      Left = Stack.empty() ? 0 : Stack.top() + 1;
      Result = std::max(Result, Height[K] * (N - Left));
    }
  }
  return static_cast<int>(Result);
}
