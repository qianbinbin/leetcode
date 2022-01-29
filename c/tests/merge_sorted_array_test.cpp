#include <gtest/gtest.h>

extern "C" {
#include "merge_sorted_array.h"
}

TEST(merge_sorted_array_test, merge_88_1) {
    int nums11[] = {1, 2, 3, 0, 0, 0}, m1 = 3;
    int nums12[] = {2, 5, 6}, n1 = 3;
    std::vector<int> expected1{1, 2, 2, 3, 5, 6};
    merge_88_1(nums11, sizeof(nums11) / sizeof(nums11[0]), m1, nums12,
               sizeof(nums12) / sizeof(nums12[0]), n1);
    EXPECT_EQ(expected1, std::vector<int>(nums11, nums11 + sizeof(nums11) /
                                                           sizeof(nums11[0])));

    int nums21[] = {1}, m2 = 1;
    int nums22[] = {}, n2 = 0;
    std::vector<int> expected2{1};
    merge_88_1(nums21, sizeof(nums21) / sizeof(nums21[0]), m2, nums22,
               sizeof(nums22) / sizeof(nums22[0]), n2);
    EXPECT_EQ(expected2, std::vector<int>(nums21, nums21 + sizeof(nums21) /
                                                           sizeof(nums21[0])));

    int nums31[] = {0}, m3 = 0;
    int nums32[] = {1}, n3 = 1;
    std::vector<int> expected3{1};
    merge_88_1(nums31, sizeof(nums31) / sizeof(nums31[0]), m3, nums32,
               sizeof(nums32) / sizeof(nums32[0]), n3);
    EXPECT_EQ(expected3, std::vector<int>(nums31, nums31 + sizeof(nums31) /
                                                           sizeof(nums31[0])));
}
