#include "BestTimeToBuyAndSellStock.h"
#include <limits>

using namespace lcpp;

int Solution121_1::maxProfit(std::vector<int> &prices) {
  int Min = std::numeric_limits<int>::max(), Result = 0;
  for (const auto &Price : prices) {
    Result = std::max(Result, Price - Min);
    Min = std::min(Min, Price);
  }
  return Result;
}
