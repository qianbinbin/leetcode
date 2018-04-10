#include <gtest/gtest.h>

extern "C" {
#include <search-insert-position.h>
}

TEST(leetcode_35, normal) {
    int nums[] = {1, 3, 5, 6};
    EXPECT_EQ(searchInsert_35(nums, 4, 5), 2);
    EXPECT_EQ(searchInsert_35(nums, 4, 2), 1);
    EXPECT_EQ(searchInsert_35(nums, 4, 7), 4);
    EXPECT_EQ(searchInsert_35(nums, 4, 0), 0);
}
