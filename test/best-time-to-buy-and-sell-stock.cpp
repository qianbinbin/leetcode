#include <gtest/gtest.h>

extern "C" {
#include <best-time-to-buy-and-sell-stock.h>
}

TEST(leetcode_121, normal) {
    int nums[] = {7, 1, 5, 3, 6, 4};
    EXPECT_EQ(maxProfit_121(nums, 6), 5);
}
