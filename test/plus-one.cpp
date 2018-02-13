#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <plus-one.h>
}

TEST(leetcode_66, normal) {
    int digits[] = {9, 9, 9, 9};
    print_array(digits, 4);
    int size = 0;
    int *result = plusOne_66(digits, 4, &size);
    EXPECT_EQ(size, 5);
    print_array(result, size);
    free(result);
}
