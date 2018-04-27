#include <gtest/gtest.h>

extern "C" {
#include <generate-parentheses.h>
}

TEST(leetcode_22_1, normal) {
    int size = 0;
    char **parenthesis = generateParenthesis_22_1(3, &size);
    for (int i = 0; i < size; ++i) {
        puts(parenthesis[i]);
        free(parenthesis[i]);
    }
    free(parenthesis);
}

TEST(leetcode_22_2, normal) {
    int size = 0;
    char **parenthesis = generateParenthesis_22_2(3, &size);
    for (int i = 0; i < size; ++i) {
        puts(parenthesis[i]);
        free(parenthesis[i]);
    }
    free(parenthesis);
}
