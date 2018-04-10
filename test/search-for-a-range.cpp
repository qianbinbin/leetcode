#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <search-for-a-range.h>
}

TEST(leetcode_34, normal) {
    int nums[] = {5, 7, 7, 8, 8, 10};
    int size = 0;
    int *indexes = searchRange_34(nums, 6, 8, &size);
    array_print(indexes, size);
    free(indexes);
}
