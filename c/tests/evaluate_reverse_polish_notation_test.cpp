#include <gtest/gtest.h>

extern "C" {
#include "evaluate_reverse_polish_notation.h"
}

#define ARR_SIZE(a) (sizeof(a) / sizeof((a)[0]))

char *tokens1[] = {"2", "1", "+", "3", "*"};

char *tokens2[] = {"4", "13", "5", "/", "+"};

char *tokens3[] = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};

TEST(evaluate_reverse_polish_notation_test, evalRPN_150_1) {
    EXPECT_EQ(evalRPN_150_1(tokens1, ARR_SIZE(tokens1)), 9);
    EXPECT_EQ(evalRPN_150_1(tokens2, ARR_SIZE(tokens2)), 6);
    EXPECT_EQ(evalRPN_150_1(tokens3, ARR_SIZE(tokens3)), 22);
}
