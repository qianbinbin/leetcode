#include "PermutationSequence.h"
#include <cassert>
#include <vector>

using namespace lcpp;

std::string Solution60_1::getPermutation(int n, int k) {
  assert(1 <= n && n <= 9 && "n must be between 1 and 9 inclusive!");
  int Factorial[10];
  Factorial[0] = 1;
  for (int I = 1; I <= n; ++I)
    Factorial[I] = Factorial[I - 1] * I;
  assert(1 <= k && k <= Factorial[n]
             && "k must be between 1 and n! inclusive!");

  std::string Numbers = "123456789";
  std::string Permutation;
  --k;
  const auto &Begin = Numbers.begin();
  for (int I = 0, Index; n > 0; ++I, --n) {
    Index = k / Factorial[n - 1];
    Permutation.push_back(Numbers[Index]);
    Numbers.erase(Begin + Index);
    k %= Factorial[n - 1];
  }
  return Permutation;
}
