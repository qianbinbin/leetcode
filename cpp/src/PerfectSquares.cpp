#include "PerfectSquares.h"
#include <cassert>
#include <unordered_set>
#include <vector>

using namespace lcpp;

int Solution279_1::numSquares(int n) {
  assert(n > 0);
  std::vector<int> Nums(n + 1);
  std::vector<int> Squares;
  for (int I = 1, Square; (Square = I * I) <= n; ++I) {
    Nums[Square] = 1;
    Squares.push_back(Square);
  }
  if (Nums[n] != 0)
    return 1;
  std::vector<int> Pre = Squares, Cur;
  for (int K = 2, Sum;; ++K) {
    for (const auto &Square : Squares) {
      for (const auto &I : Pre) {
        if ((Sum = Square + I) > n || Nums[Sum] != 0)
          continue;
        Nums[Sum] = K;
        Cur.push_back(Sum);
        if (Sum == n)
          return K;
      }
    }
    std::swap(Pre, Cur);
    Cur.clear();
  }
}

std::vector<int> &Solution279_2::getNums() {
  static std::vector<int> Nums{0};
  return Nums;
}

int Solution279_2::numSquares(int n) {
  assert(n > 0);
  auto &Nums = getNums();
  if (Nums.size() > n)
    return Nums[n];
  for (int N, I, Diff, Num; (N = Nums.size()) <= n;) {
    for (I = 1, Num = Max; (Diff = N - I * I) >= 0; ++I)
      Num = std::min(Num, Nums[Diff] + 1);
    Nums.push_back(Num);
  }
  return Nums[n];
}

int Solution279_3::numSquares(int n) {
  assert(n > 0);
  std::unordered_set<int> Set({n}), Tmp;
  std::vector<int> Squares;
  for (int I = 1, S; (S = I * I) <= n; ++I)
    Squares.push_back(S);
  for (int Level = 1; !Set.empty(); ++Level) {
    for (const auto &N : Set) {
      for (const auto &S : Squares) {
        if (N == S)
          return Level;
        if (N < S)
          break;
        else
          Tmp.insert(N - S);
      }
    }
    Set.clear();
    std::swap(Set, Tmp);
  }
  return -1;
}
