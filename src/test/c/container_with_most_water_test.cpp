#include <gtest/gtest.h>

extern "C" {
#include <container_with_most_water.h>
}

TEST(leetcode_11, normal) {
    int nums[] = {4, 1, 3, 2, 1};
    EXPECT_EQ(maxArea_11(nums, 5), 6);
}
