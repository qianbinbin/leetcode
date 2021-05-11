#include <gtest/gtest.h>

extern "C" {
#include "trapping_rain_water.h"
}

TEST(trapping_rain_water_test, trap_42_1) {
    int height1[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int const heightSize1 = 12, expected1 = 6;
    EXPECT_EQ(expected1, trap_42_1(height1, heightSize1));

    int height2[] = {4, 2, 0, 3, 2, 5};
    int const heightSize2 = 6, expected2 = 9;
    EXPECT_EQ(expected2, trap_42_1(height2, heightSize2));
}

TEST(trapping_rain_water_test, trap_42_2) {
    int height1[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int const heightSize1 = 12, expected1 = 6;
    EXPECT_EQ(expected1, trap_42_2(height1, heightSize1));

    int height2[] = {4, 2, 0, 3, 2, 5};
    int const heightSize2 = 6, expected2 = 9;
    EXPECT_EQ(expected2, trap_42_2(height2, heightSize2));
}

TEST(trapping_rain_water_test, trap_42_3) {
    int height1[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int const heightSize1 = 12, expected1 = 6;
    EXPECT_EQ(expected1, trap_42_3(height1, heightSize1));

    int height2[] = {4, 2, 0, 3, 2, 5};
    int const heightSize2 = 6, expected2 = 9;
    EXPECT_EQ(expected2, trap_42_3(height2, heightSize2));
}
