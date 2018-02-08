#include <gtest/gtest.h>

extern "C" {
#include <permutation-sequence.h>
}

TEST(leetcode_60_1, normal) {
    char *str = getPermutation_60_1(3, 3);
    ASSERT_TRUE(str != NULL);
    EXPECT_STREQ(str, "213");
    free(str);
}

TEST(leetcode_60_2, normal) {
    char *str = getPermutation_60_2(3, 3);
    ASSERT_TRUE(str != NULL);
    EXPECT_STREQ(str, "213");
    free(str);
}
