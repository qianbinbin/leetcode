#include <gtest/gtest.h>

extern "C" {
#include "trapping_rain_water.h"
}

TEST(trapping_rain_water_test, trap_42_1) {
    int nums[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    EXPECT_EQ(trap_42_1(nums, 12), 6);
}

TEST(trapping_rain_water_test, trap_42_2) {
    int nums[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    EXPECT_EQ(trap_42_2(nums, 12), 6);
}

TEST(trapping_rain_water_test, trap_42_3) {
    int nums[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    EXPECT_EQ(trap_42_3(nums, 12), 6);
}
