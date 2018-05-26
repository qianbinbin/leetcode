#include <gtest/gtest.h>

extern "C" {
#include "letter_combinations_of_a_phone_number.h"
}

TEST(letter_combinations_of_a_phone_number_test, letterCombinations_17_1) {
    int size = 0;
    char **combinations = letterCombinations_17_1("23", &size);
    for (int i = 0; i < size; ++i) {
        puts(combinations[i]);
        free(combinations[i]);
    }
    free(combinations);
}
