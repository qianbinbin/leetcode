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
