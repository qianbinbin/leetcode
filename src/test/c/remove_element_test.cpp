#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <remove_element.h>
}

TEST(leetcode_27, normal) {
    int nums[] = {3, 2, 2, 3};
    array_print(nums, 4);
    int size = removeElement_27(nums, 4, 3);
    EXPECT_EQ(size, 2);
    array_print(nums, size);
}
