#include <gtest/gtest.h>

extern "C" {
#include "valid_parentheses.h"
}

TEST(valid_parentheses_test, isValid_20_1) {
    EXPECT_TRUE(isValid_20_1("()"));
    EXPECT_TRUE(isValid_20_1("()[]{}"));
    EXPECT_FALSE(isValid_20_1("(]"));
    EXPECT_FALSE(isValid_20_1("([)]"));
    EXPECT_TRUE(isValid_20_1("{[]}"));
}
