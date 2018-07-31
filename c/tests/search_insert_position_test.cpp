#include <gtest/gtest.h>

extern "C" {
#include "search_insert_position.h"
}

TEST(search_insert_position_test, searchInsert_35_1) {
    int nums[] = {1, 3, 5, 6};
    EXPECT_EQ(searchInsert_35_1(nums, 4, 5), 2);
    EXPECT_EQ(searchInsert_35_1(nums, 4, 2), 1);
    EXPECT_EQ(searchInsert_35_1(nums, 4, 7), 4);
    EXPECT_EQ(searchInsert_35_1(nums, 4, 0), 0);
}
