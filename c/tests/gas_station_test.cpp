#include <gtest/gtest.h>

extern "C" {
#include "gas_station.h"
}

#define ARR_SIZE(a) (sizeof(a) / sizeof((a)[0]))

TEST(gas_station_test, canCompleteCircuit_134_1) {
    int gas1[] = {1, 2, 3, 4, 5};
    int cost1[] = {3, 4, 5, 1, 2};
    EXPECT_EQ(3, canCompleteCircuit_134_1(gas1, ARR_SIZE(gas1), cost1,
                                          ARR_SIZE(cost1)));

    int gas2[] = {2, 3, 4};
    int cost2[] = {3, 4, 3};
    EXPECT_EQ(-1, canCompleteCircuit_134_1(gas2, ARR_SIZE(gas2), cost2,
                                           ARR_SIZE(cost2)));
}
