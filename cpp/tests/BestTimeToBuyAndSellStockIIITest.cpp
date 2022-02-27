#include "BestTimeToBuyAndSellStockIII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(BestTimeToBuyAndSellStockIII, Solution123_1) {
  auto S123_1 = Solution123_1();

  std::vector<int> Prices1{3, 3, 5, 0, 0, 3, 1, 4};
  int const Expected1 = 6;
  EXPECT_EQ(Expected1, S123_1.maxProfit(Prices1));

  std::vector<int> Prices2{1, 2, 3, 4, 5};
  int const Expected2 = 4;
  EXPECT_EQ(Expected2, S123_1.maxProfit(Prices2));

  std::vector<int> Prices3{7, 6, 4, 3, 1};
  int const Expected3 = 0;
  EXPECT_EQ(Expected3, S123_1.maxProfit(Prices3));
}

TEST(BestTimeToBuyAndSellStockIII, Solution123_2) {
  auto S123_2 = Solution123_2();

  std::vector<int> Prices1{3, 3, 5, 0, 0, 3, 1, 4};
  int const Expected1 = 6;
  EXPECT_EQ(Expected1, S123_2.maxProfit(Prices1));

  std::vector<int> Prices2{1, 2, 3, 4, 5};
  int const Expected2 = 4;
  EXPECT_EQ(Expected2, S123_2.maxProfit(Prices2));

  std::vector<int> Prices3{7, 6, 4, 3, 1};
  int const Expected3 = 0;
  EXPECT_EQ(Expected3, S123_2.maxProfit(Prices3));
}
