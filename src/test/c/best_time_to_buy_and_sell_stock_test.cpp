#include <gtest/gtest.h>

extern "C" {
#include <best_time_to_buy_and_sell_stock.h>
}

TEST(leetcode_121, normal) {
    int nums[] = {7, 1, 5, 3, 6, 4};
    EXPECT_EQ(maxProfit_121(nums, 6), 5);
}
