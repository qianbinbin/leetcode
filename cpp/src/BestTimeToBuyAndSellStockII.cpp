#include "BestTimeToBuyAndSellStockII.h"

using namespace lcpp;

int Solution122_1::maxProfit(std::vector<int> &prices) {
  int Profit = 0;
  for (std::vector<int>::size_type I = 1, E = prices.size(); I < E; ++I) {
    if (prices[I] > prices[I - 1])
      Profit += prices[I] - prices[I - 1];
  }
  return Profit;
}
