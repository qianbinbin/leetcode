#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <4sum.h>
}

TEST(leetcode_18, normal) {
    int nums[] = {1, 0, -1, 0, -2, 2};
    print_array(nums, 6);
    int size = 0;
    int **quadruplets = fourSum_18(nums, 6, 0, &size);
    ASSERT_TRUE(quadruplets != NULL);
    EXPECT_EQ(size, 3);
    for (int i = 0; i < size; ++i) {
        print_array(quadruplets[i], 4);
        free(quadruplets[i]);
    }
    free(quadruplets);
}
