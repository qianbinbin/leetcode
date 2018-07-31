#include <gtest/gtest.h>

extern "C" {
#include "edit_distance.h"
}

TEST(edit_distance_test, minDistance_72_1) {
    EXPECT_EQ(minDistance_72_1("horse", "ros"), 3);
    EXPECT_EQ(minDistance_72_1("intention", "execution"), 5);
}
