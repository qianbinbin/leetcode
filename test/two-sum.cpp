#include <gtest/gtest.h>

extern "C" {
#include <two-sum.h>
}

TEST(leetcode_1, empty) {
    int nums[] = {};
    int *result = twoSum_1(nums, 0, 0);
    ASSERT_TRUE(result == NULL);
}

TEST(leetcode_1, normal) {
    int nums[] = {2, 7, 11, 15};
    int *result = twoSum_1(nums, 4, 9);
    ASSERT_TRUE(result != NULL);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 1);
    free(result);
}

TEST(leetcode_1, same_element) {
    int nums[] = {2, 7, 11, 15};
    int *result = twoSum_1(nums, 4, 4);
    ASSERT_TRUE(result == NULL);
}
