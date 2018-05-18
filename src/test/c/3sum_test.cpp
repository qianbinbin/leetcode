#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <3sum.h>
}

TEST(leetcode_15, normal) {
    int nums[] = {-4, -2, 1, -5, -4, -4, 4, -2, 0, 4, 0, -2, 3, 1, -5, 0};
    array_print(nums, 16);
    int size = 0;
    int **triplets = threeSum_15(nums, 16, &size);
    ASSERT_TRUE(triplets != NULL);
    EXPECT_EQ(size, 6);
    for (int i = 0; i < size; ++i) {
        array_print(triplets[i], 3);
        free(triplets[i]);
    }
    free(triplets);
}
