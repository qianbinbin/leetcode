#include <gtest/gtest.h>

extern "C" {
#include "best_time_to_buy_and_sell_stock_iii.h"
}

#define ARR_SIZE(a) (sizeof(a) / sizeof((a)[0]))

TEST(best_time_to_buy_and_sell_stock_iii_test, maxProfit_123_1) {
    int prices1[] = {3, 3, 5, 0, 0, 3, 1, 4};
    EXPECT_EQ(maxProfit_123_1(prices1, ARR_SIZE(prices1)), 6);
    int prices2[] = {1, 2, 3, 4, 5};
    EXPECT_EQ(maxProfit_123_1(prices2, ARR_SIZE(prices2)), 4);
    int prices3[] = {7, 6, 4, 3, 1};
    EXPECT_EQ(maxProfit_123_1(prices3, ARR_SIZE(prices3)), 0);
}

TEST(best_time_to_buy_and_sell_stock_iii_test, maxProfit_123_2) {
    int prices1[] = {3, 3, 5, 0, 0, 3, 1, 4};
    EXPECT_EQ(maxProfit_123_2(prices1, ARR_SIZE(prices1)), 6);
    int prices2[] = {1, 2, 3, 4, 5};
    EXPECT_EQ(maxProfit_123_2(prices2, ARR_SIZE(prices2)), 4);
    int prices3[] = {7, 6, 4, 3, 1};
    EXPECT_EQ(maxProfit_123_2(prices3, ARR_SIZE(prices3)), 0);
}
