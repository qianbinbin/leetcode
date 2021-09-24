#include "PermutationSequence.h"

using namespace lcpp;

std::string Solution60_1::getPermutation(int n, int k) {
  int Factorial[10];
  Factorial[0] = 1;
  for (int I = 1; I <= n; ++I)
    Factorial[I] = Factorial[I - 1] * I;

  std::string Numbers = "123456789";
  std::string Permutation;
  --k;
  const auto &Begin = Numbers.begin();
  for (int I; n > 0; --n) {
    I = k / Factorial[n - 1];
    Permutation.push_back(Numbers[I]);
    Numbers.erase(Begin + I);
    k %= Factorial[n - 1];
  }
  return Permutation;
}
