#include <gtest/gtest.h>

extern "C" {
#include "generate_parentheses.h"
}

TEST(generate_parentheses_test, generateParenthesis_22_1) {
    int const N1 = 3;
    std::vector<std::string> Expected1{"((()))", "(()())", "(())()", "()(())",
                                       "()()()"};
    int returnSize1 = 0;
    char **actual1 = generateParenthesis_22_1(N1, &returnSize1);
    EXPECT_EQ(Expected1.size(), returnSize1);
    for (int i = 0; i < returnSize1; ++i) {
        EXPECT_EQ(Expected1[i], actual1[i]);
        free(actual1[i]);
    }
    free(actual1);

    int const N2 = 1;
    std::vector<std::string> Expected2{"()"};
    int returnSize2 = 0;
    char **actual2 = generateParenthesis_22_1(N2, &returnSize2);
    EXPECT_EQ(Expected2.size(), returnSize2);
    for (int i = 0; i < returnSize2; ++i) {
        EXPECT_EQ(Expected2[i], actual2[i]);
        free(actual2[i]);
    }
    free(actual2);
}
