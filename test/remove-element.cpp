#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <remove-element.h>
}

TEST(leetcode_27, normal) {
    int nums[] = {3, 2, 2, 3};
    print_array(nums, 4);
    int size = removeElement_27(nums, 4, 3);
    EXPECT_EQ(size, 2);
    print_array(nums, size);
}
