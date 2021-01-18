#include "BestTimeToBuyAndSellStockII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(BestTimeToBuyAndSellStockII, Solution122_1) {
  std::vector<int> Prices1{7, 1, 5, 3, 6, 4};
  const int Expected1 = 7;
  EXPECT_EQ(Expected1, Solution122_1().maxProfit(Prices1));

  std::vector<int> Prices2{1, 2, 3, 4, 5};
  const int Expected2 = 4;
  EXPECT_EQ(Expected2, Solution122_1().maxProfit(Prices2));

  std::vector<int> Prices3{7, 6, 4, 3, 1};
  const int Expected3 = 0;
  EXPECT_EQ(Expected3, Solution122_1().maxProfit(Prices3));
}