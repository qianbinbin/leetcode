#include <gtest/gtest.h>

extern "C" {
#include <letter-combinations-of-a-phone-number.h>
}

TEST(leetcode_17, empty) {
    char *digits = "";
    int size = 0;
    char **combinations = letterCombinations_17(digits, &size);
    printf("size=%d\n", size);
    for (int i = 0; i < size; ++i) {
        puts(combinations[i]);
        free(combinations[i]);
    }
    free(combinations);
}

TEST(leetcode_17, normal) {
    char *digits = "23";
    int size = 0;
    char **combinations = letterCombinations_17(digits, &size);
    for (int i = 0; i < size; ++i) {
        puts(combinations[i]);
        free(combinations[i]);
    }
    free(combinations);
}
