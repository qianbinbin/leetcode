#include "BestTimeToBuyAndSellStockIII.h"
#include <limits>

using namespace lcpp;

int Solution123_1::maxProfit(std::vector<int> &prices) {
  int Hold1 = std::numeric_limits<int>::min(), Release1 = 0, Hold2 = Hold1,
      Release2 = 0;
  for (const auto &Price : prices) {
    Release2 = std::max(Release2, Price + Hold2);
    Hold2 = std::max(Hold2, Release1 - Price);
    Release1 = std::max(Release1, Price + Hold1);
    Hold1 = std::max(Hold1, -Price);
  }
  return Release2;
}

int Solution123_2::maxProfit(std::vector<int> &prices) {
  const auto &Size = prices.size();
  std::vector<int> Dp1(Size), Dp2(Size);
  int Min = prices[0];
  for (std::vector<int>::size_type I = 1; I != Size; ++I) {
    Dp1[I] = std::max(Dp1[I - 1], prices[I] - Min);
    Min = std::min(Min, prices[I]);
  }
  int Max = prices[Size - 1];
  for (std::vector<int>::size_type I = Size - 2, E = -1; I != E; --I) {
    Dp2[I] = std::max(Dp2[I + 1], Max - prices[I]);
    Max = std::max(Max, prices[I]);
  }
  int Result = 0;
  for (std::vector<int>::size_type I = 0; I != Size; ++I)
    Result = std::max(Result, Dp1[I] + Dp2[I]);
  return Result;
}
