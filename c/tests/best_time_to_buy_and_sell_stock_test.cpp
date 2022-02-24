#include <gtest/gtest.h>

extern "C" {
#include "best_time_to_buy_and_sell_stock.h"
}

#define ARR_SIZE(a) (sizeof(a) / sizeof((a)[0]))

TEST(best_time_to_buy_and_sell_stock_test, maxProfit_121_1) {
    int prices1[] = {7, 1, 5, 3, 6, 4};
    EXPECT_EQ(5, maxProfit_121_1(prices1, ARR_SIZE(prices1)));

    int prices2[] = {7, 6, 4, 3, 1};
    EXPECT_EQ(0, maxProfit_121_1(prices2, ARR_SIZE(prices2)));
}
