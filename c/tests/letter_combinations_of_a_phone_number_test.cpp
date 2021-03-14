#include <gtest/gtest.h>

extern "C" {
#include "letter_combinations_of_a_phone_number.h"
}

TEST(letter_combinations_of_a_phone_number_test, letterCombinations_17_1) {
    char digits1[] = "23";
    int returnSize1 = 0;
    std::vector<std::string> const expected1{"ad", "ae", "af", "bd", "be", "bf",
                                             "cd", "ce", "cf"};
    char **actual1 = letterCombinations_17_1(digits1, &returnSize1);
    EXPECT_EQ(expected1.size(), returnSize1);
    for (int i = 0; i < returnSize1; ++i) {
        EXPECT_EQ(expected1[i], actual1[i]);
        free(actual1[i]);
    }
    free(actual1);

    char digits2[] = "";
    int returnSize2 = 0;
    std::vector<std::string> const expected2{};
    char **actual2 = letterCombinations_17_1(digits2, &returnSize2);
    EXPECT_EQ(expected2.size(), returnSize2);
    for (int i = 0; i < returnSize2; ++i) {
        EXPECT_EQ(expected2[i], actual2[i]);
        free(actual2[i]);
    }
    free(actual2);

    char digits3[] = "2";
    int returnSize3 = 0;
    std::vector<std::string> const expected3{"a", "b", "c"};
    char **actual3 = letterCombinations_17_1(digits3, &returnSize3);
    EXPECT_EQ(expected3.size(), returnSize3);
    for (int i = 0; i < returnSize3; ++i) {
        EXPECT_EQ(expected3[i], actual3[i]);
        free(actual3[i]);
    }
    free(actual3);
}
