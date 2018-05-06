#include <gtest/gtest.h>

extern "C" {
#include <edit-distance.h>
}

TEST(leetcode_72, normal) {
    EXPECT_EQ(minDistance_72("horse", "ros"), 3);
    EXPECT_EQ(minDistance_72("intention", "execution"), 5);
}
