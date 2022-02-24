#include "BestTimeToBuyAndSellStock.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(BestTimeToBuyAndSellStock, Solution121_1) {
  auto S121_1 = Solution121_1();

  std::vector<int> Prices1{7, 1, 5, 3, 6, 4};
  int const Expected1 = 5;
  EXPECT_EQ(Expected1, S121_1.maxProfit(Prices1));

  std::vector<int> Prices2{7, 6, 4, 3, 1};
  int const Expected2 = 0;
  EXPECT_EQ(Expected2, S121_1.maxProfit(Prices2));
}