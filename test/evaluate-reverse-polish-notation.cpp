#include <gtest/gtest.h>

extern "C" {
#include <evaluate-reverse-polish-notation.h>
}

TEST(leetcode_150, normal) {
    char *tokens[] = {"2", "1", "+", "3", "*"};
    EXPECT_EQ(evalRPN_150(tokens, 5), 9);
    char *tokens1[] = {"4", "13", "5", "/", "+"};
    EXPECT_EQ(evalRPN_150(tokens1, 5), 6);
    char *tokens2[] = {"3", "-4", "+"};
    EXPECT_EQ(evalRPN_150(tokens2, 3), -1);
}
