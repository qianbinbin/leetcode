#include <gtest/gtest.h>

extern "C" {
#include <gas-station.h>
}

TEST(leetcode_134, normal) {
    int gas[] = {4, 3, 4, 8, 1, 4, 5};
    int cost[] = {5, 4, 1, 2, 3, 4, 5};
    EXPECT_EQ(canCompleteCircuit_134(gas, 7, cost, 7), 2);
}
