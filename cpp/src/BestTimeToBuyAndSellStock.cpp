#include "BestTimeToBuyAndSellStock.h"
#include <limits>

using namespace lcpp;

int Solution121_1::maxProfit(std::vector<int> &prices) {
  int Min = std::numeric_limits<int>::max(), Profit = 0;
  for (const auto &Price : prices) {
    Profit = std::max(Profit, Price - Min);
    Min = std::min(Min, Price);
  }
  return Profit;
}
