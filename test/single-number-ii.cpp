#include <gtest/gtest.h>

extern "C" {
#include <single-number-ii.h>
}

TEST(leetcode_137_1, normal) {
    int nums[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 4};
    EXPECT_EQ(singleNumber_137_1(nums, 10), 4);
}
