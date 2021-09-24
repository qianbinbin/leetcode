#include <gtest/gtest.h>

extern "C" {
#include "permutation_sequence.h"
}

TEST(permutation_sequence_test, getPermutation_60_1) {
    char *str1 = getPermutation_60_1(3, 3);
    EXPECT_STREQ("213", str1);
    free(str1);

    char *str2 = getPermutation_60_1(4, 9);
    EXPECT_STREQ("2314", str2);
    free(str2);

    char *str3 = getPermutation_60_1(3, 1);
    EXPECT_STREQ("123", str3);
    free(str3);
}
