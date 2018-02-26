#include <gtest/gtest.h>

extern "C" {
#include <single-number.h>
}

TEST(leetcode_136, normal) {
    int nums[] = {1, 2, 3, 4, 5, 1, 2, 3, 4};
    EXPECT_EQ(singleNumber_136(nums, 9), 5);
}
