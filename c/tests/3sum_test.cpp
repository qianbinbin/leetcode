#include <gtest/gtest.h>

extern "C" {
#include "3sum.h"
}

TEST(three_sum_test, threeSum_15_1) {
    int nums1[] = {-1, 0, 1, 2, -1, -4};
    int numsSize1 = 6, returnSize1 = 0, *columnSizes1;
    const std::vector<std::vector<int>> expected1{{-1, -1, 2},
                                                  {-1, 0,  1}};
    int **actual1 = threeSum_15_1(nums1, numsSize1, &returnSize1,
                                  &columnSizes1);
    for (int i = 0; i < returnSize1; ++i) {
        EXPECT_EQ(expected1[i],
                  std::vector<int>(actual1[i], actual1[i] + columnSizes1[i]));
        free(actual1[i]);
    }
    free(actual1);
    free(columnSizes1);

    int nums2[] = {};
    int numsSize2 = 0, returnSize2 = 0, *columnSizes2;
    const std::vector<std::vector<int>> expected2{};
    int **actual2 = threeSum_15_1(nums2, numsSize2, &returnSize2,
                                  &columnSizes2);
    for (int i = 0; i < returnSize2; ++i) {
        EXPECT_EQ(expected2[i],
                  std::vector<int>(actual2[i], actual2[i] + columnSizes2[i]));
        free(actual2[i]);
    }
    free(actual2);
    free(columnSizes2);

    int nums3[] = {0};
    int numsSize3 = 1, returnSize3 = 0, *columnSizes3;
    const std::vector<std::vector<int>> expected3{};
    int **actual3 = threeSum_15_1(nums3, numsSize3, &returnSize3,
                                  &columnSizes3);
    for (int i = 0; i < returnSize3; ++i) {
        EXPECT_EQ(expected3[i],
                  std::vector<int>(actual3[i], actual3[i] + columnSizes3[i]));
        free(actual3[i]);
    }
    free(actual3);
    free(columnSizes3);
}
