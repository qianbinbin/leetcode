#include <gtest/gtest.h>

extern "C" {
#include "edit_distance.h"
}

TEST(edit_distance_test, minDistance_72_1) {
    EXPECT_EQ(3, minDistance_72_1("horse", "ros"));
    EXPECT_EQ(5, minDistance_72_1("intention", "execution"));
}
