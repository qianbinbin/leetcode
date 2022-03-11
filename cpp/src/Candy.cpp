#include "Candy.h"

using namespace lcpp;

int Solution135_1::candy(std::vector<int> &ratings) {
  const auto &E = ratings.size();
  std::vector<int> Candies(E, 1);
  for (std::vector<int>::size_type I = 1; I != E; ++I) {
    if (ratings[I] > ratings[I - 1])
      Candies[I] = Candies[I - 1] + 1;
  }
  int Result = Candies[E - 1];
  for (std::vector<int>::size_type I = E - 2, E1 = -1; I != E1; --I) {
    if (ratings[I] > ratings[I + 1])
      Candies[I] = std::max(Candies[I], Candies[I + 1] + 1);
    Result += Candies[I];
  }
  return Result;
}
