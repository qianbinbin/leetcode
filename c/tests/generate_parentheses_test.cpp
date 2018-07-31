#include <gtest/gtest.h>

extern "C" {
#include "generate_parentheses.h"
}

TEST(generate_parentheses_test, generateParenthesis_22_1) {
    int size = 0;
    char **parenthesis = generateParenthesis_22_1(3, &size);
    for (int i = 0; i < size; ++i) {
        puts(parenthesis[i]);
        free(parenthesis[i]);
    }
    free(parenthesis);
}
