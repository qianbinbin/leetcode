#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "search_for_a_range.h"
}

TEST(search_for_a_range_test, searchRange_34_1) {
    int nums[] = {5, 7, 7, 8, 8, 10};

    int size1 = 0;
    int *range1 = searchRange_34_1(nums, 6, 8, &size1);
    array_print(range1, size1);
    free(range1);

    int size2 = 0;
    int *range2 = searchRange_34_1(nums, 6, 6, &size2);
    array_print(range2, size2);
    free(range2);
}
