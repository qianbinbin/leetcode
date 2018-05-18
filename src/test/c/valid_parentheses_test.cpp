#include <gtest/gtest.h>

extern "C" {
#include <valid_parentheses.h>
}

TEST(leetcode_20, normal) {
    EXPECT_TRUE(isValid_20(""));
    EXPECT_TRUE(isValid_20("{{[[]]}}"));
    EXPECT_TRUE(isValid_20("({[]})"));
    EXPECT_FALSE(isValid_20("[][][[[["));
    EXPECT_FALSE(isValid_20("()()[{{]]}}"));
    EXPECT_FALSE(isValid_20("}}{"));
}
