#include <gtest/gtest.h>

extern "C" {
#include "search_insert_position.h"
}

TEST(search_insert_position_test, searchInsert_35_1) {
    int nums[] = {1, 3, 5, 6};
    EXPECT_EQ(2, searchInsert_35_1(nums, 4, 5));
    EXPECT_EQ(1, searchInsert_35_1(nums, 4, 2));
    EXPECT_EQ(4, searchInsert_35_1(nums, 4, 7));
    EXPECT_EQ(0, searchInsert_35_1(nums, 4, 0));

    int nums5[] = {1};
    EXPECT_EQ(0, searchInsert_35_1(nums5, 1, 0));
}
